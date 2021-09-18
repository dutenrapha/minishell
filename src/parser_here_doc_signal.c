/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_here_doc_signal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:36:49 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/18 15:03:19 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	int_here_doc(int signal)
{
	(void) signal;
	g_minishell.erro = 130;
	write(1, "\n", 1);
	exit(130);
}
