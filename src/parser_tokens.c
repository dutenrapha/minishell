/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 22:07:36 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/12 13:45:33 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static void	check_pipe(t_token *tokens, int *last_pipe_in)
{
	t_token	*current;

	current = tokens;
	while (current)
	{
		if (current->type == T_PIPE)
		{
			command_parser(tokens, current, last_pipe_in);
			tokens = current->next;
			check_pipe(tokens, last_pipe_in);
			break ;
		}
		current = current->next;
	}
	if (!current)
		command_parser(tokens, current, last_pipe_in);
}

void	parse_tokens(t_token *tokens)
{
	int	last_pipe_in;

	if (!tokens)
		return ;
	last_pipe_in = 0;
	check_pipe(tokens, &last_pipe_in);
	if (last_pipe_in != 0)
		close(last_pipe_in);
}
