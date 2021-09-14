/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_unset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:39:23 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/14 12:08:05 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static int	ret_error(char *key)
{
	ft_putstr_fd(key, 2);
	ft_putstr_fd(": not a valid identifier\n", 2);
	free(key);
	return (1);
}

int	lsh_unset(char **args)
{
	char	*key;

	args = (args + 1);
	while (*args)
	{
		key = *args;
		if (ft_strchr(key, '?'))
			return (ret_error(key));
		if (ht_bool_search(g_minishell.env, key))
			ht_delete(g_minishell.env, key);
		if (ht_bool_search(g_minishell.local_var, key))
			ht_delete(g_minishell.local_var, key);
		args = (args + 1);
	}
	return (0);
}
