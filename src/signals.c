/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 18:01:27 by rdutenke          #+#    #+#             */
/*   Updated: 2021/09/07 18:11:30 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	stop_process(int signal)
{
	(void)signal;
	g_minishell.erro = 130;
	write(1, "\n", 1);
}

static void	reload_process(int signal)
{
	(void)signal;
	g_minishell.erro = 130;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

static void	kill_process(int signal)
{
	(void)signal;
	g_minishell.erro = 131;
	ft_printf("Quit (core dumped)\n");
}

void	exec_signals(void)
{
	signal(SIGINT, stop_process);
	signal(SIGQUIT, kill_process);
}

void	loop_signals(void)
{
	signal(SIGINT, reload_process);
	signal(SIGQUIT, SIG_IGN);
}
