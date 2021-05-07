/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:00:48 by rdutenke          #+#    #+#             */
/*   Updated: 2021/05/07 22:56:08 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	lsh_loop(void)
{
	char	*line;
	char	**args;
	int		status;

	while (status)
	{
		printf("> ");
		line = lsh_read_line();
		args = ft_split(line, LSH_TOK_DELIM);
		status = lsh_execute(args);
		free(line);
		free(args);
	}
}