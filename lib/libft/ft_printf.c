/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/24 09:23:50 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/24 13:36:28 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_free(t_ptf *parms)
{
	free(parms->flag);
	parms->flag = NULL;
	free(parms->v_str);
	parms->v_str = NULL;
	parms->v_p = NULL;
	parms->asterisk = 0;
	parms->v_ast = 0;
	parms->v_char = 0;
	parms->v_c = 0;
	parms->v_int = 0;
	parms->conversion = '\0';
	parms->width = 0;
	parms->precision = -1;
}

static void	ft_init_pms(t_ptf *parms, const char *str)
{
	parms->len_c = 0;
	parms->flag = NULL;
	parms->str = NULL;
	parms->str = (char *)str;
	parms->v_c = 0;
	parms->v_str = NULL;
	parms->v_p = NULL;
	parms->asterisk = 0;
	parms->v_ast = 0;
	parms->v_char = 0;
	parms->v_int = 0;
	parms->conversion = '\0';
	parms->width = 0;
	parms->precision = -1;
	parms->len = ft_strlen(str);
	parms->slen = ft_strlen(str);
	parms->i = 0;
}

int	ft_printf(const char *str, ...)
{
	t_ptf	parms;

	ft_init_pms(&parms, str);
	va_start(parms.ap, str);
	while (parms.i < parms.slen)
	{
		if (parms.str[parms.i] == '%')
		{
			ft_check_flag(&parms);
			ft_free(&parms);
		}
		else
		{
			ft_putchar_fd(str[parms.i], 1);
			parms.i += 1;
		}
	}
	va_end(parms.ap);
	return (parms.len);
}
