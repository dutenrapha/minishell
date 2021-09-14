/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 22:23:42 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/14 00:43:22 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

char	*ht_search(t_hashtable *table, char *key)
{
	int			index;
	t_ht_item	*item;

	index = hash_function(key, table->size);
	item = table->items[index];
	if (item == NULL)
		return (NULL);
	while (item->next != NULL && ft_strcmp(item->key, key) != 0)
		item = item->next;
	if (ft_strcmp(item->key, key) == 0)
		return (item->value);
	return (NULL);
}

int	ht_bool_search(t_hashtable *table, char *key)
{
	int			index;
	t_ht_item	*item;

	index = hash_function(key, table->size);
	item = table->items[index];
	if (item == NULL)
		return (0);
	while (item->next != NULL && ft_strcmp(item->key, key) != 0)
		item = item->next;
	if (ft_strcmp(item->key, key) == 0)
		return (1);
	return (0);
}