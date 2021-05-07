/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 18:26:36 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/24 13:34:48 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_aux(char *base, uintmax_t *base_len, int *cont_num)
{
	*base_len = ft_strlen(base);
	*cont_num = 1;
}

char	*ft_itoa_base(uintmax_t nb, char *base)
{
	int			cont_num;
	uintmax_t	base_len;
	uintmax_t	aux;
	char		*str;

	ft_aux(base, &base_len, &cont_num);
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
