/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_izer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:33:05 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/12 11:15:18 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static void	tokenize_quoted(t_tokendata *tk, char quote)
{
	if (tk->input[tk->i] == quote)
	{
		tk->buffer[tk->j++] = tk->input[tk->i];
		tk->state = S_GENERAL;
	}
	else
		tk->buffer[tk->j++] = tk->input[tk->i];
}

static void	special_tkchar(t_tokendata *tk, t_token **tokens)
{
	get_token(tk, tokens);
	tk->buffer[tk->j++] = tk->input[tk->i];
	if (tk->input[tk->i] == LESS && tk->input[tk->i + 1] == LESS)
		tk->buffer[tk->j++] = tk->input[++tk->i];
	else if (tk->input[tk->i] == GREATER && tk->input[tk->i + 1] == GREATER)
		tk->buffer[tk->j++] = tk->input[++tk->i];
	get_token(tk, tokens);
}

static void	tokenize_general(t_tokendata *tk, t_token **tokens)
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

t_token	*tokenizer(char *input)
{
	t_token		*tokens;
	t_tokendata	*tk;

	tokens = NULL;
	tk = ft_calloc(1, sizeof (*tk));
	tk->input = input;
	while (tk->input[tk->i])
	{
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
	return (tokens);
}
