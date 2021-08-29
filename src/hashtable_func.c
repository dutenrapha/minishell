/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 19:27:49 by aalcara-          #+#    #+#             */
/*   Updated: 2021/08/29 17:55:54 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

unsigned long	hash_function(char *str, unsigned int size)
{
	unsigned long	hash;
	int				i;

	hash = 5381;
	i = 0;
	while (str[i] && str)
	{
		hash = ((hash << 5) + hash) + str[i];
		i++;
	}
	return (hash % size);
}
