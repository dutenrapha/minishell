/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 22:29:41 by rdutenke          #+#    #+#             */
/*   Updated: 2020/04/27 22:30:53 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*src;
	unsigned char	*dest;

	if (str1 == NULL && str2 == NULL)
	{
		return (str1);
	}
	else
	{
		dest = (unsigned char *)str1;
		src = (unsigned char *)str2;
		i = 0;
		while (i < n)
		{
			*(dest + i) = *(src + i);
			i++;
		}
		return (dest);
	}
}
