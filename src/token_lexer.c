/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_lexer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:33:05 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/18 16:09:33 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static int	lex_dquote(char *str, char **dest)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[i] != D_QUOTE)
	{
		if (str[i] == '$')
		{
			while ((str + i)[len] != D_QUOTE && (str + i)[len] != SPACE)
				len++;
			expand_variable((str + i), dest, &i, len);
		}
		else
			*dest = ft_strjoinrealloc(*dest, (str + i), 1);
		i++;
	}
	return (i + 1);
}

static int	lex_squote(char *str, char **dest)
{
	int	i;

	i = 0;
	while (str[i] != S_QUOTE)
		i++;
	if (i >= 1)
		*dest = ft_strjoinrealloc(*dest, str, i);
	return (i + 1);
}

static void	ft_straddchr(char **str, char c)
{
	int		len;
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

static void	handle_word_token(t_token *token)
{
	char	*temp;
	int		i;
	int		len;

	i = 0;
	len = 0;
	temp = ft_strdup(token->value);
	ft_bzero(token->value, ft_strlen(token->value));
	while (temp[i] != C_NULL)
	{
		if (temp[i] == D_QUOTE && check_is_closed((temp + i), D_QUOTE))
			i += lex_dquote((temp + i + 1), &token->value);
		else if (temp[i] == S_QUOTE && check_is_closed((temp + i), S_QUOTE))
			i += lex_squote((temp + i + 1), &token->value);
		else if (temp[i] == '$')
		{
			len = ft_strlen(temp + i);
			expand_variable((temp + i), &token->value, &i, len);
		}
		else
			ft_straddchr(&token->value, temp[i]);
		i++;
	}
	free(temp);
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
		token->type = T_PIPE;
	else
	{
		handle_word_token(token);
		token->type = T_WORD;
	}
}
