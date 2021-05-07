/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countword.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 22:21:13 by rdutenke          #+#    #+#             */
/*   Updated: 2020/04/27 22:22:37 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countword(char const *s1, char c)
{
	int	len;
	int	n;
	int	i;

	len = ft_strlen(s1);
	n = 0;
	i = -1;
	while (++i < len + 1)
	{
		if (*(s1 + i) == c || *(s1 + i) == '\0')
		{
			if (*(s1 + i - 1) != c)
			{
				n++;
			}
		}
	}
	return (n);
}
