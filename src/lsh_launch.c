/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_launch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 21:13:17 by rdutenke          #+#    #+#             */
/*   Updated: 2021/09/11 21:34:05 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	lsh_launch(char **args)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	pid = fork();
	exec_signals();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
			ft_printf("error -1\n");
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
		{
			wpid = waitpid(pid, &status, WUNTRACED);
		}
	}
	return (1);
}
