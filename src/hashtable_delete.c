/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:52:23 by aalcara-          #+#    #+#             */
/*   Updated: 2021/08/29 19:57:54 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	check_item(t_ht_item *prev, t_ht_item *item, char *key)
{
	if (ft_strcmp(item->key, key) == 0)
	{
		prev->next = item->next;
		free_item(item);
		return (1);
	}
	else if (item->next)
		return (check_item(prev->next, item->next, key));
	return (0);
}

void	ht_delete(t_hashtable *table, char *key)
{
	int			index;
	t_ht_item	*item;

	index = hash_function(key, table->size);
	item = table->items[index];
	if (item == NULL)
		return ;
	if (ft_strcmp(item->key, key) == 0)
	{
		table->items[index] = item->next;
		free_item(item);
		table->count--;
		return ;
	}
	if (check_item(item, item->next, key) == 1)
		table->count--;
}
