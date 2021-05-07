/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 22:32:25 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/24 13:35:01 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*pointer;

	pointer = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		*(pointer + i) = (unsigned char)c;
		i++;
	}
	return (str);
}
