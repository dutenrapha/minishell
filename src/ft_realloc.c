/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 22:22:33 by rdutenke          #+#    #+#             */
/*   Updated: 2021/05/07 22:42:14 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static size_t	ft_getsize(void * p)
{
	size_t	* in;

	in = p;
	if (in)
	{
		--in;
		return *in;
	}
	return -1;
}


void *ft_realloc(void *ptr, size_t size)
{
	void	*newptr;
	size_t	msize;

	msize = ft_getsize(ptr);
	if (size <= msize)
		return ptr;
	newptr = malloc(size);
	ft_memcpy(newptr, ptr, msize);
	free(ptr);
	return newptr;
}