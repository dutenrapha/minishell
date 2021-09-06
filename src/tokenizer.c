/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:33:05 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/06 16:03:10 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"


char	*expand_word(char *key)
{
	char *aux;

	aux = ht_search(g_minishell.env, (key + 1));
	return (aux);
}

bool	check_is_closed(char *str, char quote)
{
	int	i;
	
	i = 1;
	while (str[i] != quote && str[i] != '\0')
		i++;
	if (str[i] == quote)
		return (TRUE);
	return (FALSE);
}

char	*ft_strljoinrealloc(char *s1, char *s2, int len)
{
	char *aux;
	char *aux2;
	int	s1len;

	s1len = ft_strlen(s1);
	aux = ft_substr(s2, 0, len);
	aux2 = malloc(sizeof(char) * (s1len + len + 1));
	aux2 = ft_strjoin(s1, aux);
	free(aux);
	free(s1);
	return (aux2);
}
int	lex_dquote(char *str, char **dest)
{
	int	i;
	char *aux;

	i = 0;
	while (str[i] != D_QUOTE && str[i] != '$')
	{
		i++;
	}
	// printf("dest = %s, str = %s, i = %i\n", *dest, str, i);// !remover
	if (i > 1)
		*dest = ft_strljoinrealloc(*dest, str, i);
	if (str[i] == '$')
	{
		aux = expand_word(str + i);
		ft_strlcat(*dest, aux, ft_strlen(aux));
		i += strlen(str + i);
	}
	return (i + 1);
}

int	lex_squote(char *str, char **dest)
{
	int	i;

	i = 0;
	while (str[i] != S_QUOTE)
		i++;
	if (i > 1)
		*dest = ft_strljoinrealloc(*dest, str, i);
	return (i + 1);
}

void	ft_straddchr(char **str, char c)
{
	int	len;
	char	*aux;

	len = ft_strlen (*str);
	aux = malloc(sizeof(char) * (len + 2));
	ft_strcpy(aux, *str);
	free(*str);
	aux[len] = c;
	aux[len + 1] = '\0';
	*str = ft_strdup(aux);
	free(aux);
	
}

void	handle_word_token(t_token *token)
{
	char	*temp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	temp = ft_strdup(token->value);
	ft_bzero(token->value, ft_strlen(token->value));
	while (temp[i] != C_NULL)
	{
		// printf("char = %c\n", temp[i]);// !excluir
		if (temp[i] == D_QUOTE && check_is_closed((temp + i), D_QUOTE))
			i += lex_dquote((temp + i + 1), &token->value);
		else if (temp[i] == S_QUOTE && check_is_closed((temp + i), S_QUOTE))
			i += lex_squote((temp + i + 1), &token->value);
		// TODO else if $ expand
		else
			ft_straddchr(&token->value, temp[i]);
		if (temp[i] != C_NULL)
			i++;
	}
	token->type = T_WORD;
	free(temp);
}

bool	special_token(t_token *token, const char *str)
{
	int	res;

	res = ft_strcmp(token->value, str);
	if (res == 0)
		return (TRUE);
	return (FALSE);
}

void	lexer(t_token *token)
{
	if (special_token(token, ">"))
		token->type = T_OREDIRECT;
	else if (special_token(token, "<"))
		token->type = T_IREDIRECT;
	else if (special_token(token, ">>"))
		token->type = T_OAPPEND;
	else if (special_token(token, "<<"))
		token->type = T_HERE_DOC;
	else if (special_token(token, "|"))
		token->type = T_HERE_DOC;
	else
		handle_word_token(token);
	// printf("token->type = %d, value = [%s]\n\n", token->type, token->value);//!remover
}

void	push_token(t_token **tokens, t_token *new)
{
	t_token	*aux;

	if (!*tokens)
		*tokens = new;
	else
	{
		aux = *tokens;
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
}

void	get_token(t_tokendata *tk, t_token **tokens)
{
	t_token	*token;

	// printf("tk->i = %ld\ntk->buffer: [%s]\n", tk->i, tk->buffer); //!remover
	token = malloc(sizeof(*token));
	if (!tk->j || !token)
		return ;
	ft_bzero(token, sizeof(*token));
	token->value = ft_strdup(tk->buffer);
	token->type = tk->type;
	token->next = NULL;
	lexer(token);
	push_token(tokens, token);
	ft_bzero(tk->buffer, tk->j);
	tk->type = T_UNDEFINED;
	tk->j = 0;
}



void	tokenize_quoted(t_tokendata *tk, char quote)
{
	
	if (tk->input[tk->i] == quote)
	{
		tk->buffer[tk->j++] = tk->input[tk->i];
		tk->state = S_GENERAL;
	}
	else
		tk->buffer[tk->j++] = tk->input[tk->i];
}



void	special_tkchar(t_tokendata *tk, t_token **tokens)
{
	get_token(tk, tokens);
	tk->buffer[tk->j++] = tk->input[tk->i];
	if (tk->input[tk->i] == LESS && tk->input[tk->i + 1] == LESS)
		tk->buffer[tk->j++] = tk->input[++tk->i];
	else if (tk->input[tk->i] == GREATER && tk->input[tk->i + 1] == GREATER)
		tk->buffer[tk->j++] = tk->input[++tk->i];
	get_token(tk, tokens);
}

void	tokenize_general(t_tokendata *tk, t_token **tokens)
{
	if (tk->input[tk->i] == S_QUOTE || tk->input[tk->i] == D_QUOTE)
	{
		if (tk->input[tk->i] == S_QUOTE)
			tk->state = S_SQUOTE;
		else
			tk->state = S_DQUOTE;
		tk->buffer[tk->j++] = tk->input[tk->i];
	}
	else if (ft_strchr("|<>", tk->input[tk->i]))
		special_tkchar(tk, tokens);
	else if (tk->input[tk->i] == SPACE)
		get_token(tk, tokens);
	else
		tk->buffer[tk->j++] = tk->input[tk->i];

}

void	print_tokens(t_token **tokens)
{
	t_token	*aux;
	int		i;

	i = 0;
	aux = *tokens;
	printf("\n");
	while (aux)
	{
		printf("token %d: %s\n", i, aux->value);
		i++;
		aux = aux->next;
	}
}

t_token	*tokenizer(char *input)
{
	t_token		*tokens;
	t_tokendata	*tk;

	tokens = NULL;
	tk = ft_calloc(1, sizeof (*tk));
	tk->input = input;
	while (tk->input[tk->i])
	{
		// printf("input[%ld] = %c, state = %d\n", tk->i, tk->input[tk->i], tk->state);
		if (tk->state == S_GENERAL)
			tokenize_general(tk, &tokens);
		else if (tk->state == S_DQUOTE)
			tokenize_quoted(tk, D_QUOTE);
		else if (tk->state == S_SQUOTE)
			tokenize_quoted(tk, S_QUOTE);
		if (tk->input[tk->i + 1] == C_NULL)
			get_token(tk, &tokens);
		tk->i++;
	}
	free(tk);
	print_tokens(&tokens);//!apenas teste
	return (tokens);
}
