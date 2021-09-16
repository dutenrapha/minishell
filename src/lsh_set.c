/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:18:31 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/13 14:22:45 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	lsh_set(char **args)
{
	char	**array;
	int		i;

	if (args[0] == NULL)
		args[0] = args[0];
	array = hashtable_to_array(g_minishell.local_var);
	i = 0;
	while (array[i])
	{
		ft_putstr_fd(array[i], 1);
		ft_putstr_fd("\n", 1);
		free(array[i]);
		i++;
	}
	free(array);
	return (1);
}
