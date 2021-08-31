/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:28:18 by aalcara-          #+#    #+#             */
/*   Updated: 2021/08/28 14:39:25 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	free_item(t_ht_item *item)
{
	free(item->key);
	free(item->value);
	free(item);
}

void	free_all_itens(t_ht_item *item)
{
	if (item->next)
		free_all_itens(item->next);
	free_item(item);
}

void	free_table(t_hashtable *table)
{
	t_ht_item	*item;
	int			i;

	i = 0;
	while (i < table->size)
	{
		item = table->items[i];
		i++;
		if (item != NULL)
		{
			free_all_itens(item);
		}
	}
	free(table->items);
	free(table);
}
