/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 23:21:56 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/24 14:05:48 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_first_count(int *resto, int *i, int *n)
{
	while (*resto != 0 || *n != 0)
	{
		*resto = *n % 10;
		*n = *n / 10;
		*i += 1;
	}
}

static	void	ft_start_struct(t_pf *params, int n)
{
	params->itoa = NULL;
	params->n_orig = n;
	params->resto = 1;
	params->i = -1;
	params->passo = 0;
	ft_first_count(&params->resto, &params->i, &n);
}

static	void	ft_last_count(t_pf *params)
{
	while (params->n_orig != 0)
	{
		params->resto = params->n_orig % 10;
		params->n_orig = params->n_orig / 10;
		*(params->itoa + params->i + params->passo) = params->resto + 48;
		params->i -= 1;
	}
}

static	void	ft_aux(t_pf *params)
{
	*params->itoa = '-';
	params->n_orig = -1 * params->n_orig;
	params->passo = 0;
}

char	*ft_itoa(int n)
{
	t_pf	itoa_p;

	ft_start_struct(&itoa_p, n);
	if (itoa_p.i == 0)
	{
		itoa_p.i += 1;
		itoa_p.itoa = (char *)ft_calloc(itoa_p.i + 1, sizeof(char));
		*itoa_p.itoa = 48;
	}
	if (itoa_p.n_orig < 0)
	{
		itoa_p.itoa = (char *)ft_calloc(itoa_p.i + 2, sizeof(char));
		ft_aux(&itoa_p);
	}
	else if (itoa_p.n_orig != 0)
	{
		itoa_p.itoa = (char *)ft_calloc(itoa_p.i + 1, sizeof(char));
		itoa_p.passo = -1;
	}
	n = itoa_p.n_orig;
	ft_last_count(&itoa_p);
	return (itoa_p.itoa);
}
