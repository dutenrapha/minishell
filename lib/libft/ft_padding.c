/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 18:41:34 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/27 22:09:50 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_aux_l(int size, t_ptf *pms)
{
	ft_print_padding(size, ' ');
	if (size > 0)
		pms->len += pms->width - pms->len_c;
	if (pms->v_char == 1)
	{
		ft_putchar_fd('\0', 1);
	}
	else
	{
		ft_putstr_fd(pms->v_str, 1);
	}
}

static void	ft_aux_r(int size, t_ptf *pms)
{
	if (size > 0)
		pms->len += pms->width - pms->len_c;
	if (pms->v_char == 1)
	{
		ft_putchar_fd('\0', 1);
	}
	else
	{
		ft_putstr_fd(pms->v_str, 1);
	}
	ft_print_padding(size, ' ');
}

static void	ft_aux_0(int size, t_ptf *pms)
{
	if (pms->v_str[0] == '-' && size > 0)
	{
		ft_putchar_fd('-', 1);
		size--;
		pms->v_str[0] = '0';
	}
	ft_print_padding(size, '0');
	if (size >= 0)
		pms->len += pms->width - pms->len_c;
	if (pms->v_char == 1)
	{
		ft_putchar_fd('\0', 1);
	}
	else
	{
		ft_putstr_fd(pms->v_str, 1);
	}
}

static void	ft_aux(t_ptf *pms)
{
	pms->len += 1;
	pms->len_c = 1;
	pms->v_str = (char *)ft_calloc(2, sizeof(char));
	pms->v_str[0] = '%';
}

void	ft_padding(char type, t_ptf *pms)
{
	int	size;

	size = 0;
	if (pms->conversion == '%')
		ft_aux(pms);
	if (pms->v_str != NULL && pms->conversion != '\0')
	{
		size = pms->width - pms->len_c;
		if (pms->conversion == 'c' && pms->v_str[0] == '\0')
		{
			size--;
			if (pms->width <= 1)
				pms->len += 1;
		}
		if (type == 'l')
			ft_aux_l(size, pms);
		if (type == 'r')
			ft_aux_r(size, pms);
		if (type == '0')
			ft_aux_0(size, pms);
	}
}
