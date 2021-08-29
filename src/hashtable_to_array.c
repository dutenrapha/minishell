/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_to_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 14:48:00 by aalcara-          #+#    #+#             */
/*   Updated: 2021/08/29 19:58:53 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

char	*join_item(t_ht_item *item)
{
	char	*join_item;
	int		len;

	len = ft_strlen(item->key) + ft_strlen(item->value) + 2;
	join_item = (char *)ft_calloc(sizeof(char), len);
	ft_strcpy(join_item, item->key);
	ft_strlcat(join_item, "=", len);
	ft_strlcat(join_item, item->value, len);
	return (join_item);
}

char	**hashtable_to_array(t_hashtable *table)
{
	int			i;
	t_ht_item	*item;
	char		**array;
	int			j;

	i = 0;
	j = 0;
	array = (char **)ft_calloc(sizeof(char *), (table->count + 1));
	while (i < table->size)
	{
		item = table->items[i];
		if (item)
		{
			array[j] = join_item(item);
			j++;
			while (item->next)
			{
				item = item->next;
				array[j] = join_item(item);
				j++;
			}
		}
		i++;
	}
	return (array);
}
