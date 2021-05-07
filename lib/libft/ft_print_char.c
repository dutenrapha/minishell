/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:46:03 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/24 13:35:08 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(t_ptf *parms)
{
	char	*temp;

	temp = NULL;
	temp = (char *)ft_calloc(2, sizeof(char));
	if (!temp)
		return ;
	parms->v_c = va_arg(parms->ap, int);
	if (parms->v_c == 0)
	{
		parms->v_char = 1;
	}
	else
	{
		temp[0] = (char)parms->v_c;
	}
	parms->v_str = ft_strdup(temp);
	free(temp);
	parms->len_c = ft_strlen(parms->v_str);
	parms->len += ft_strlen(parms->v_str);
}
