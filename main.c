/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:00:40 by rdutenke          #+#    #+#             */
/*   Updated: 2021/09/16 14:20:57 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/header.h"

int	main(void)
{
	g_minishell.env = env_to_hashtable(__environ);
	g_minishell.erro = 0;
	g_minishell.local_var = create_table(LOCAL_HASHTABLE_SIZE);
	lsh_loop();
	return (EXIT_SUCCESS);
}
