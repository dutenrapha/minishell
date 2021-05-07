/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 22:54:26 by rdutenke          #+#    #+#             */
/*   Updated: 2020/04/27 22:56:18 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*strmapi;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	strmapi = (char *)ft_calloc(len + 1, sizeof(char));
	if (!strmapi)
	{
		return (NULL);
	}
	while (i < len)
	{
		*(strmapi + i) = f(i, *(s + i));
		i++;
	}
	return (strmapi);
}
