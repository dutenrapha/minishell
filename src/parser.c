/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 22:07:36 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/12 10:12:13 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int		get_length(t_token *start, t_token *end)
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

char	**fill_array(t_token *start, t_token *end, char **command)
{
	int i;

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



void	restore_std_fd(int *save_fd)
{
	dup2(save_fd[0], STDIN_FILENO);
	close(save_fd[0]);
	dup2(save_fd[1], STDOUT_FILENO);
	close(save_fd[1]);
}

void	create_pipe(t_token *pipe_token, int *last_pipe_in)
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

free_command(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	while (i > 0)
	{
		free(array[i -1]);
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
	lsh_execute(command);
	free_command(command);
	restore_std_fd(save_std_fd);
	

	//!remover
	int i = 0;
	printf("\n");
	while (command[i])
	{
		printf("%s\n", command[i]);
		i++;
	}
}





void	check_pipe(t_token *tokens, int *last_pipe_in)
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