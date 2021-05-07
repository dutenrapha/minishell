/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 22:49:04 by rdutenke          #+#    #+#             */
/*   Updated: 2020/04/27 22:50:17 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	len_dst;

	len_dst = ft_strlen(dst);
	if (size <= len_dst)
	{
		return (size + ft_strlen((char *)src));
	}
	j = 0;
	while (*(src + j) != '\0' && len_dst < size - 1)
	{
		*(dst + len_dst) = *(src + j);
		len_dst++;
		j++;
	}
	*(dst + len_dst) = '\0';
	return (len_dst + ft_strlen(&src[j]));
}
