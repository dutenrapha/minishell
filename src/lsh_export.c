/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_export.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:39:23 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/18 20:11:48 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static int	get_key_and_value(char *str, char **key, char **value)
{
	char	*aux;

	*key = ft_strdup(str);
	aux = ht_search(g_minishell.local_var, *key);
	if (aux == NULL)
	{
		free(*key);
		return (1);
	}
	*value = ft_strdup(aux);
	return (0);
}

static int	check_invalid_char(char *args)
{
	int		j;

	j = 0;
	while (args[j] != '=' && args[j] != C_NULL)
	{
		if (args[j] == SPACE || args[j] == '?')
		{
			error_return("export", NOT_VALID_IDENT, 1);
			return (1);
		}
		j++;
	}
	return (0);
}

static void	do_the_job(char *key, char *value)
{
	ht_insert(g_minishell.local_var, key, value);
	ht_insert(g_minishell.env, key, value);
	free(key);
	free(value);
}

int	lsh_export(char **args)
{
	int		i;
	int		check;
	char	*key;
	char	*value;

	i = 1;
	while (args[i])
	{
		if (check_invalid_char(args[i]) == 1)
			return (1);
		if (ft_strchr(args[i], '='))
		{
			key = find_key(args[i]);
			value = find_value(args[i]);
			check = 0;
		}
		else
			check = get_key_and_value(args[i], &key, &value);
		if (check == 0)
			do_the_job(key, value);
		i++;
	}
	return (0);
}
