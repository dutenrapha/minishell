/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_set_local_var.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:30:57 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/18 20:20:03 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	set_local_var(char **args)
{
	char	*key;
	char	*value;

	if (args[1])
	{
		return ;
	}
	key = find_key(args[0]);
	value = find_value(args[0]);
	ht_insert(g_minishell.local_var, key, value);
	if (ht_bool_search(g_minishell.env, key))
		ht_insert(g_minishell.env, key, value);
	free(key);
	free(value);
}
