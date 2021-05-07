/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 16:06:27 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/27 22:03:20 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_aux(t_ptf *parms, char *text)
{
	char	*temp2;
	int		diff;
	int		i;

	temp2 = NULL;
	diff = 0;
	i = -1;
	diff = parms->precision - parms->len_c;
	if (diff > 0)
	{
		temp2 = NULL;
		temp2 = (char *)ft_calloc(parms->precision + 1, sizeof(char));
		ft_memset(temp2, '0', parms->precision);
		while (++i < parms->len_c)
		{
			temp2[diff + i] = text[i];
		}
		parms->len_c = ft_strlen(temp2);
	}
	else
	{
		temp2 = ft_strdup(text);
	}
	return (temp2);
}

void	ft_print_p(t_ptf *parms)
{
	char	*temp;
	char	*temp2;

	temp = NULL;
	temp2 = NULL;
	parms->v_p = va_arg(parms->ap, void *);
	temp = ft_itoa_base((intptr_t)parms->v_p, HEX_BASE_L);
	parms->len_c = ft_strlen(temp);
	temp2 = ft_aux(parms, temp);
	free(temp);
	if (*temp2 == '0' && parms->precision == 0)
		parms->v_str = ft_strjoin("0x", "");
	else
	{
		parms->v_str = ft_strjoin("0x", temp2);
	}
	free(temp2);
	parms->len_c = ft_strlen(parms->v_str);
	parms->len += ft_strlen(parms->v_str);
}
