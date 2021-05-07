/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 16:57:22 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/24 13:33:57 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_aux(t_ptf *pms, char *pos)
{
	char	*temp;
	int		init;
	int		f;
	int		length;

	length = 0;
	temp = NULL;
	init = 0;
	f = 0;
	length = ft_strlen(pms->flag);
	init = length - ft_strlen(pos) + 1;
	f = length - ft_strlen(ft_strrchr(pms->flag, pms->conversion));
	temp = ft_substr(pms->flag, init, f - init);
	pms->precision = ft_atoi(temp);
	free(temp);
}

void	ft_check_precision(t_ptf *pms)
{
	int		temp2;
	char	*pos;

	temp2 = 0;
	pos = NULL;
	pos = ft_strchr(pms->flag, '.');
	if (pos != NULL)
	{
		if (*(pos + 1) == '*')
		{
			temp2 = va_arg(pms->ap, int);
			if (temp2 < 0)
				pms->precision = -1;
			else
				pms->precision = temp2;
		}
		else
		{
			ft_aux(pms, pos);
		}
	}
}
