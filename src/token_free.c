/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 10:45:12 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/12 11:14:50 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	free_tokens(t_token **tokens)
{
	if (!(*tokens))
		return ;
	if ((*tokens)->next)
		free_tokens(&(*tokens)->next);
	free((*tokens)->value);
	free(*tokens);
	*tokens = NULL;
}
