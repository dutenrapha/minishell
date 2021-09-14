/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:52:23 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/14 02:52:24 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static t_ht_item	*find_previous_item(t_ht_item *start, int i)
{
	int			pos;
	t_ht_item	*previous;

	pos = 1;
	previous = start;
	while (pos < i)
	{
		previous = previous->next;
		pos++;
	}
	return (previous);
}

static int	handle_collision(t_ht_item *current, t_ht_item *item)
{
	t_ht_item	*previous;
	t_ht_item	*start;
	int			i;

	i = 0;
	start = current;
	while (current->next != NULL && ft_strcmp(current->key, item->key) != 0)
	{
		current = current->next;
		i++;
	}
	if (ft_strcmp(current->key, item->key) == 0)
	{
		previous = find_previous_item(start, i);
		previous->next = item;
		item->next = current->next;
		free_item(current);
		return (0);
	}
	current->next = item;
	return (1);
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
		{
			table->items[index] = item;
			item->next = current_item->next;
			free_item(current_item);
		}
		else
			table->count += handle_collision(current_item, item);
	}
}
