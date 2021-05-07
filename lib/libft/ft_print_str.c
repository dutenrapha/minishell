/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:46:30 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/24 13:36:10 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(t_ptf *parms)
{
	char	*temp;

	temp = NULL;
	parms->v_str = va_arg(parms->ap, char *);
	if (parms->v_str == NULL)
		parms->v_str = ft_strdup("(null)");
	else
		parms->v_str = ft_substr(parms->v_str, 0, ft_strlen(parms->v_str));
	parms->len_c = ft_strlen(parms->v_str);
	if (parms->precision < parms->len_c && parms->precision >= 0)
	{
		temp = ft_strdup(parms->v_str);
		free(parms->v_str);
		parms->v_str = NULL;
		parms->v_str = ft_substr(temp, 0, parms->precision);
		free(temp);
		parms->len_c = ft_strlen(parms->v_str);
	}
	parms->len += ft_strlen(parms->v_str);
}
