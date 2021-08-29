/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 14:47:03 by aalcara-          #+#    #+#             */
/*   Updated: 2021/08/29 20:00:00 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	lsh_env(char **args)
{
	char	**env_array;
	int		i;

	if (args[0] == NULL)
		args[0] = args[0];
	env_array = hashtable_to_array(g_minishell.env);
	i = 0;
	while (env_array[i])
	{
		ft_putstr_fd(env_array[i], 1);
		ft_putstr_fd("\n", 1);
		free(env_array[i]);
		i++;
	}
	free(env_array);
	return (1);
}
