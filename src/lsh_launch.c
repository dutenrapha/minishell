/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_launch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 21:13:17 by rdutenke          #+#    #+#             */
/*   Updated: 2021/09/18 16:47:07 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	lsh_launch(char **args)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;
	char	**env;

	pid = fork();
	exec_signals();
	if (pid == 0)
	{
		env = hashtable_to_array(g_minishell.env);
		if (execve(args[0], args, env) == -1)
			error_return(args[0], NOT_FOUND, 127);
		exit(EXIT_FAILURE);
	}
	if (pid < 0)
		ft_printf("error -1\n");
	else
	{
		wpid = waitpid(pid, &status, WUNTRACED);
		if (wpid == 0)
			wpid = (pid_t)wpid;
		while (!WIFEXITED(status) && !WIFSIGNALED(status))
			wpid = waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}
