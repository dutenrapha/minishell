/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 19:51:37 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/12 13:26:01 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcpy(char *dst, const char *src)
{
	unsigned int		i;
	char				temp;

	if (src == NULL)
		return (0);
	i = 0;
	temp = src[i];
	while (temp != '\0')
	{
		dst[i] = temp;
		i++;
		temp = src[i];
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
