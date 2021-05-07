/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:44:57 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/24 13:34:23 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flag_width(t_ptf *parms)
{
	ft_check_precision(parms);
	ft_set_conversion(parms);
	if (parms->width == 0)
		ft_get_width(parms, 0);
	ft_padding('l', parms);
}
