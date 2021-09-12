/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 22:07:36 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/12 14:37:43 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static void	restore_std_fd(int *save_fd)
{
	dup2(save_fd[0], STDIN_FILENO);
	close(save_fd[0]);
	dup2(save_fd[1], STDOUT_FILENO);
	close(save_fd[1]);
}

static void	create_pipe(t_token *pipe_token, int *last_pipe_in)
{
	int	new_pipe[2];

	dup2(*last_pipe_in, STDIN_FILENO);
	if (*last_pipe_in != 0)
		close(*last_pipe_in);
	if (!pipe_token)
		return ;
	pipe(new_pipe);
	dup2(new_pipe[1], STDOUT_FILENO);
	close(new_pipe[1]);
	*last_pipe_in = dup(new_pipe[0]);
	close(new_pipe[0]);
}

static void	free_command(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	while (i > 0)
	{
		free(array[i - 1]);
		i--;
	}
	free(array);
}

void	command_parser(t_token *tokens, t_token *pipe, int *last_pipe_in)
{
	int		save_std_fd[2];
	char	**command;

	save_std_fd[0] = dup(STDIN_FILENO);
	save_std_fd[1] = dup(STDOUT_FILENO);
	create_pipe(pipe, last_pipe_in);
	// check_redirects;// TODO
	command = create_command_array(tokens, pipe);
	//!remover
	// int i = 0;
	// printf("\n");
	// while (command[i])
	// {
	// 	printf("%s\n", command[i]);
	// 	i++;
	// }
	// !até aqui
	lsh_execute(command);
	free_command(command);
	restore_std_fd(save_std_fd);
}
