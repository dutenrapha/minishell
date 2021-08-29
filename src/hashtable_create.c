/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 19:27:49 by aalcara-          #+#    #+#             */
/*   Updated: 2021/08/29 17:42:53 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

//create a pointer to a new hash table item
t_ht_item	*create_item(char *key, char *value)
{
	t_ht_item	*item;

	item = (t_ht_item *)malloc(sizeof(t_ht_item));
	item->key = (char *)malloc(ft_strlen(key) + 1);
	item->value = (char *)malloc(ft_strlen(value) + 1);
	ft_strcpy(item->key, key);
	ft_strcpy(item->value, value);
	item->next = NULL;
	return (item);
}

//create a new hastable
t_hashtable	*create_table(int size)
{
	t_hashtable	*table;
	int			i;

	table = (t_hashtable *)malloc(sizeof(t_hashtable));
	table->size = size;
	table->count = 0;
	table->items = (t_ht_item **)ft_calloc(table->size, sizeof(t_ht_item *));
	i = 0;
	while (i < table->size)
	{
		table->items[i] = NULL;
		i++;
	}
	return (table);
}
