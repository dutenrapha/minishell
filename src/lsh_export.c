/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:39:23 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/14 12:37:45 by aalcara-         ###   ########.fr       */
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

static int	get_key_and_value(char *str, char **key, char **value)
{
	char	*aux;

	*key = ft_strdup(str);
	aux = ht_search(g_minishell.local_var, *key);
	if (!(aux))
	{
		free(*key);
		return (1);
	}
	*value = ft_strdup(aux);
	return (0);
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
		}
		else
			if (get_key_and_value(args[i], &key, &value) == 1)
				return (0);
		if (ft_strchr(key, SPACE) || ft_strchr(key, '?'))
			return (ret_error(key, value));
		ht_insert(g_minishell.local_var, key, value);
		ht_insert(g_minishell.env, key, value);
		free(key);
		free(value);
		i++;
	}
	return (0);
}
