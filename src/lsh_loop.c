/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:00:48 by rdutenke          #+#    #+#             */
/*   Updated: 2021/09/12 14:41:03 by aalcara-         ###   ########.fr       */
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
	int		status;
	t_token	*tokens;
	// char	**args;

	status = 1;
	while (status)
	{
		loop_signals();
		line = readline("T-RexShell$ 🦖$ ");
		add_history(line);
		tokens = tokenizer(line);

		// if (args == NULL)
		// {
		// 	ft_printf("exit\n");
		// 	return ;
		// }
		free(line);
		parse_tokens(tokens);
		free_tokens(&tokens);

		// args = ft_split(line, LSH_TOK_DELIM); // ! trocar por tokenizer ------------
		// status = lsh_execute(args);
		// free_array(args);
	}
}
