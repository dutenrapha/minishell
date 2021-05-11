/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 21:02:09 by rdutenke          #+#    #+#             */
/*   Updated: 2021/05/11 16:03:05 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	lsh_cd(char **args)
{
	if (args[1] == NULL)
	{
		ft_printf("minishell: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			ft_printf("%s\n", strerror(chdir(args[1])));
		}
	}
	return (1);
}
