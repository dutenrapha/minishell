/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_read_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 22:11:40 by rdutenke          #+#    #+#             */
/*   Updated: 2021/05/11 15:37:51 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static void	ft_init(t_read	*p)
{
	p->bufsize = LSH_RL_BUFSIZE;
	p->position = 0;
	p->buffer = malloc(sizeof(char) * p->bufsize);
	if (!p->buffer)
		exit(EXIT_FAILURE);
}

char	*lsh_read_line(void)
{
	t_read	p;

	ft_init(&p);
	while (1)
	{
		p.c = ft_getchar();
		if (p.c == EOF || p.c == '\n')
		{
			p.buffer[p.position] = '\0';
			return (p.buffer);
		}
		else
		{
			p.buffer[p.position] = p.c;
		}
		p.position++;
		if (p.position >= p.bufsize)
		{
			p.bufsize += LSH_RL_BUFSIZE;
			p.buffer = ft_realloc(p.buffer, p.bufsize);
			if (!p.buffer)
				exit(EXIT_FAILURE);
		}
	}
}
