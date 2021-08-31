/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_env_to_hashtable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 14:48:00 by aalcara-          #+#    #+#             */
/*   Updated: 2021/08/29 20:01:45 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

char	*find_key(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '=')
		i++;
	return (ft_substr(str, 0, i));
}

char	*find_value(char *str)
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

t_hashtable	*env_to_hashtable(char **env)
{
	t_hashtable	*table;
	int			count;
	int			i;
	char		*key;
	char		*value;

	i = 0;
	count = 0;
	while (env[count])
		count++;
	table = create_table(count * 2);
	while (i < count)
	{
		key = find_key(env[i]);
		value = find_value(env[i]);
		ht_insert(table, key, value);
		i++;
		free(key);
		free(value);
	}
	return (table);
}
