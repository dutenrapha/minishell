/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 12:52:43 by rdutenke          #+#    #+#             */
/*   Updated: 2021/09/18 12:57:38 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	lsh_echo(char **args)
{
	bool	n_flag;
	int		i;

	i = 1;
	n_flag = false;
	if (args[1] && ft_strcmp(args[1], "-n") == 0)
	{
		n_flag = true;
		i = 2;
	}
	while (args && args[i])
	{
		ft_printf("%s ", args[i]);
		i++;
	}
	if (n_flag == false)
		ft_printf("\n");
	g_minishell.erro = 0;
	return (1);
}
