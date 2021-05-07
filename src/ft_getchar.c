/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 22:09:19 by rdutenke          #+#    #+#             */
/*   Updated: 2021/05/07 22:30:57 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int ft_getchar(void)
{
	char	buf[1];

	int n = read(0, buf, 1);

	if(n < 1)
		printf("Read failed");
	return buf[0];
}