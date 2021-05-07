/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 23:19:00 by rdutenke          #+#    #+#             */
/*   Updated: 2020/04/28 12:10:13 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*src_char;
	char	*dest_char;
	size_t	i;
	char	stop;
	int		find;

	find = 0;
	stop = (char)c;
	dest_char = (char *)dest;
	src_char = (char *)src;
	i = 0;
	while (i < n)
	{
		*(dest_char + i) = *(src_char + i);
		if (*(dest_char + i) == stop)
		{
			find = 1;
			break ;
		}
		i++;
	}
	if (find == 0 || n == 0)
		return (NULL);
	else
		return (dest_char + i + 1);
}
