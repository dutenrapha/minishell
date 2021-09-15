/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:33:05 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/15 12:55:52 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static void	push_token(t_token **tokens, t_token *new)
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

	if (!tk->j)
		return ;
	token = malloc(sizeof(*token));
	printf("tk = [type = %d]  [%s]\n", tk->type, tk->buffer);//
	if (!token)
		return ;
	ft_bzero(token, sizeof(*token));
	token->value = ft_strdup(tk->buffer);
	token->type = tk->type;
	token->next = NULL;
	printf("token = [type = %d]  [%s]\n\n\n", token->type, token->value);//
	lexer(token);
	push_token(tokens, token);
	ft_bzero(tk->buffer, tk->j);
	tk->type = T_UNDEFINED;
	tk->j = 0;
}
