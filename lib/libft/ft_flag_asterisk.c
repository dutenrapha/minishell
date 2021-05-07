/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_asterisk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:59:02 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/24 13:34:02 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_asterisk(t_ptf *parms)
{
	parms->v_ast = 1;
	parms->asterisk = va_arg(parms->ap, int);
	if (parms->asterisk > 0)
	{
		parms->width = parms->asterisk;
		ft_flag_width(parms);
	}
	else
	{
		parms->width = -1 * parms->asterisk;
		ft_flag_minus(parms);
	}
}
