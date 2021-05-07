/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_zeros.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:53:03 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/24 13:34:29 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_aux(t_ptf *parms)
{
	ft_check_precision(parms);
	ft_set_conversion(parms);
	ft_padding('r', parms);
}

void	ft_flag_zeros(t_ptf *parms)
{
	int	temp;

	temp = 0;
	if (parms->flag[1] == '*')
	{
		temp = va_arg(parms->ap, int);
		if (temp < 0)
		{
			parms->width = -temp;
			ft_aux(parms);
		}
		else
			parms->width = temp;
	}
	if (temp >= 0)
	{
		if (parms->width == 0)
			ft_get_width(parms, 1);
		ft_check_precision(parms);
		ft_set_conversion(parms);
		if (parms->len_c < (int)parms->width && parms->precision != -1)
			ft_padding('l', parms);
		else
			ft_padding('0', parms);
	}
}
