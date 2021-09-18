/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 21:07:06 by rdutenke          #+#    #+#             */
/*   Updated: 2021/09/18 12:25:05 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static bool	is_valid_second_arg(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_printf("exit\n");
			error_return("exit", "numeric argument required", 2);
			exit (g_minishell.erro);
		}
		i++;
	}
	g_minishell.erro = ft_atoi(str);
	return (TRUE);
}

int	lsh_exit(char **args)
{
	int	num_args;

	num_args = 0;
	while (args[num_args])
		num_args++;
	if (!(is_valid_second_arg(args[1])))
		return (2);
	if (num_args > 2)
	{
		error_return("exit", "Too many arguments", 1);
		return (2);
	}
	ft_printf("exit\n");
	exit (g_minishell.erro);
	return (0);
}
