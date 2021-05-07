/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 19:16:19 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/24 13:34:52 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_hex(uint32_t nb, char *base)
{
	int			cont_num;
	uintmax_t	base_len;
	uint32_t	aux;
	char		*str;

	base_len = ft_strlen(base);
	cont_num = 1;
	str = NULL;
	aux = nb / base_len;
	while (aux > 0)
	{
		cont_num++;
		aux = aux / base_len;
	}
	str = (char *)ft_calloc((cont_num + 1), sizeof(char));
	if (!str)
		return (NULL);
	cont_num--;
	while (cont_num >= 0)
	{
		str[cont_num] = base[nb % base_len];
		nb = nb / base_len;
		cont_num--;
	}
	return (str);
}
