/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_create_command_array.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 22:07:36 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/12 13:45:23 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static int	get_length(t_token *start, t_token *end)
{
	int	i;

	i = 0;
	while (start != end)
	{
		if (start->type == T_WORD)
			i++;
		start = start->next;
	}
	return (i);
}

static char	**fill_array(t_token *start, t_token *end, char **command)
{
	int	i;

	i = 0;
	while (start != end)
	{
		if (start->type == T_WORD)
		{
			command[i] = ft_strdup(start->value);
			i++;
		}
		start = start->next;
	}
	return (command);
}

char	**create_command_array(t_token *start, t_token *pipe)
{
	char	**command;
	int		length;

	length = get_length(start, pipe);
	command = (char **)malloc((length + 1) * sizeof(char *));
	command[length] = NULL;
	command = fill_array(start, pipe, command);
	return (command);
}
