/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 16:32:55 by rdutenke          #+#    #+#             */
/*   Updated: 2020/04/27 16:38:37 by raphael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, int nbyte)
{
	int				i;
	unsigned char	*pointer;

	i = 0;
	pointer = (unsigned char *)s;
	while (i < nbyte)
	{
		*(pointer + i) = '\0';
		i++;
	}
}
