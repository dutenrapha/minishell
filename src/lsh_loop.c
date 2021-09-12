/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:00:48 by rdutenke          #+#    #+#             */
/*   Updated: 2021/09/12 10:01:02 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	lsh_loop(void)
{
	char	*line;
	char	**args;
	int		status;
	t_token	*tokens;

	status = 1;
	while (status)
	{
		line = readline("T-RexShell$ 🦖$ ");
		add_history(line);
		tokens = tokenizer(line);
		parse_tokens(tokens);
		args = ft_split(line, LSH_TOK_DELIM); // ! trocar por tokenizer ------------
		// status = lsh_execute(args);
		free(line);
		free_array(args);
	}
}
