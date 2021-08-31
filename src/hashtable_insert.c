/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:52:23 by aalcara-          #+#    #+#             */
/*   Updated: 2021/08/29 20:02:17 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	handle_collision(t_ht_item *current_item, t_ht_item *item)
{
	while (current_item->next && ft_strcmp(current_item->key, item->key) != 0)
		current_item = current_item->next;
	if (ft_strcmp(current_item->key, item->key) == 0)
	{
		ft_strcpy(current_item->value, item->value);
		return (0);
	}
	else if (current_item->next == NULL)
	{
		current_item->next = item;
		return (1);
	}
	return (0);
}

void	ht_insert(t_hashtable *table, char *key, char *value)
{
	t_ht_item		*item;
	t_ht_item		*current_item;
	unsigned long	index;

	item = create_item(key, value);
	index = hash_function(key, table->size);
	current_item = table->items[index];
	if (current_item == NULL)
	{
		table->items[index] = item;
		table->count++;
	}
	else
	{
		if (ft_strcmp(current_item->key, key) == 0)
			ft_strcpy(table->items[index]->value, value);
		else
			table->count += handle_collision(current_item, item);
	}
}
