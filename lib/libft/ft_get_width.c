/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:49:07 by rdutenke          #+#    #+#             */
/*   Updated: 2020/07/27 22:12:50 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len_flag(t_ptf *parms, int k)
{
	int	i;
	int	j;
	int	end;

	end = 0;
	j = 0;
	while (1)
	{
		i = 0;
		while (BREAKS[i] != '\0' && end == 0)
		{
			if (parms->flag[j + k] == BREAKS[i])
				end = 1;
			i++;
		}
		j++;
		if (end == 1 || parms->flag[j + k] == '\0')
			break ;
	}
	return (j);
}

void	ft_get_width(t_ptf *parms, int k)
{
	int		l_flag;
	char	*temp;

	temp = NULL;
	l_flag = 0;
	l_flag = ft_len_flag(parms, k);
	temp = ft_substr(parms->flag, k, l_flag);
	parms->width = ft_atoi(temp);
	free(temp);
}
