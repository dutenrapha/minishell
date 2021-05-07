/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 23:06:23 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/24 13:37:03 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	if ((int)len <= 0 || (int)start < 0
		|| (int)start > (int)ft_strlen((char *)s) - 1)
	{
		return (ft_strdup(""));
	}
	substr = (char *)ft_calloc(len + 1, sizeof(char));
	if (!substr)
	{
		return (0);
	}
	i = 0;
	while (i < len && *(s + start) != '\0')
	{
		*(substr + i) = *(s + start);
		i++;
		start++;
	}
	*(substr + i) = '\0';
	return (substr);
}
