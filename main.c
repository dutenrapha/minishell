/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:00:40 by rdutenke          #+#    #+#             */
/*   Updated: 2021/09/07 17:58:29 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header.h"

int	main(void)
{
	g_minishell.env = env_to_hashtable(__environ);
	g_minishell.erro = 0;
	lsh_loop();
	return EXIT_SUCCESS;
}