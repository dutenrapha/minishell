/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 23:02:46 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/24 13:37:00 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strrchr(const char *s, int c)
{
	int	last;
	int	i;
	int	existe;

	existe = 0;
	last = 0;
	i = 0;
	while (*(s + i) != '\0')
	{
		if (*(s + i) == c)
		{
			last = i;
			if (existe != 1)
				existe = 1;
		}
		i++;
	}
	if (c == '\0')
		return (((char *)s + i));
	if (last == 0 && existe == 0)
		return (NULL);
	else
	{
		return ((char *)s + last);
	}
}
