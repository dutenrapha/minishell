/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 22:09:19 by rdutenke          #+#    #+#             */
/*   Updated: 2021/05/11 16:03:13 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	ft_getchar(void)
{
	char	buf[1];
	int		n;

	n = read (0, buf, 1);
	if (n < 1)
		ft_printf("Read failed\n");
	return (buf[0]);
}
