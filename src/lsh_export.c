/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:39:23 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/14 08:47:14 by aalcara-         ###   ########.fr       */
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

static int	ret_error(char *key, char *value)
{
	ft_putstr_fd(key, 2);
	ft_putstr_fd(": not a valid identifier\n", 2);
	free(key);
	free(value);
	return (1);
}

int	lsh_export(char **args)
{
	int		i;
	char	*key;
	char	*value;

	i = 1;
	while (args[i])
	{
		if (ft_strchr(args[i], '=') && !(ft_strchr(key, SPACE)))
		{
			key = find_key(args[i]);
			value = find_value(args[i]);
			if (ht_bool_search(g_minishell.local_var, key) == 1)
				ht_insert(g_minishell.local_var, key, value);
		}
		else
		{
			key = ft_strdup(args[i]);
			value = ft_strdup(ht_search(g_minishell.local_var, key));
		}
		if (ft_strchr(key, SPACE))
			return (ret_error(key, value));
		ht_insert(g_minishell.env, key, value);
		free(key);
		free(value);
		i++;
	}
	return (0);
}
