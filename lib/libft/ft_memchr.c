/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 22:26:57 by rdutenke          #+#    #+#             */
/*   Updated: 2020/04/27 22:28:33 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	int		last;
	size_t	i;
	char	*string;

	last = 0;
	i = 0;
	string = (char *)str;
	if (*(string) == c && n > 0)
	{
		return ((char *)str);
	}
	while (i < n)
	{
		if (*(string + i) == c)
		{
			last = i;
			break ;
		}
		i++;
	}
	if (last == 0)
		return (NULL);
	else
		return ((char *)str + last);
}
