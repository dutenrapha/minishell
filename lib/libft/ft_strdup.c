/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 22:43:10 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/24 13:36:48 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s1)
{
	char	*point;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (*(s1 + len) != '\0')
		len++;
	point = malloc(sizeof(char) * (len + 1));
	if (point == 0)
		return (0);
	while (*(s1 + i) != '\0')
	{
		*(point + i) = *(s1 + i);
		i++;
	}
	*(point + i) = '\0';
	return (point);
}
