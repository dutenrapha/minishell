/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 16:01:30 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/24 13:36:42 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_conversion(t_ptf *parms)
{
	if (parms->conversion == 'd' || parms->conversion == 'i')
		ft_print_int(parms);
	if (parms->conversion == 'c')
		ft_print_char(parms);
	if (parms->conversion == 's')
		ft_print_str(parms);
	if (parms->conversion == 'x')
		ft_print_x(parms);
	if (parms->conversion == 'X')
		ft_print_xup(parms);
	if (parms->conversion == 'p')
		ft_print_p(parms);
	if (parms->conversion == 'u')
		ft_print_u(parms);
}
