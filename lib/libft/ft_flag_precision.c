/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 11:33:26 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/24 13:34:20 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_precision(t_ptf *parms)
{
	if (parms->flag[1] == '*')
		parms->precision = va_arg(parms->ap, int);
	else
		ft_check_precision(parms);
	ft_set_conversion(parms);
	ft_putstr_fd(parms->v_str, 1);
}
