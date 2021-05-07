/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_read_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 22:11:40 by rdutenke          #+#    #+#             */
/*   Updated: 2021/05/07 22:44:39 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

char	*lsh_read_line(void)
{
	int		bufsize;
	int		position;
	char	*buffer;
	int		c;

	bufsize = LSH_RL_BUFSIZE;
	position = 0;
	buffer = malloc(sizeof(char) * bufsize);
	if (!buffer)
		exit(EXIT_FAILURE);
	while (1)
	{
		c = ft_getchar();
		if (c == EOF || c == '\n')
		{
			buffer[position] = '\0';
			return buffer;
		} else
		{
			buffer[position] = c;
		}
		position++;
		if (position >= bufsize)
		{
			bufsize += LSH_RL_BUFSIZE;
			buffer = ft_realloc(buffer, bufsize);
			if (!buffer)
				exit(EXIT_FAILURE);
		}
	}
}

