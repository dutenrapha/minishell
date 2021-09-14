/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_set_local_var.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 12:30:57 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/14 00:49:04 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static char	*find_key(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=')
		i++;
	return (ft_substr(str, 0, i));
}

static char	*find_value(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '=')
		i++;
	j = i;
	while (str[j] != '\0')
		j++;
	return (ft_substr(str, i + 1, j));
}

void	set_local_var(char **args)
{
	char *key;
	char *value;
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
