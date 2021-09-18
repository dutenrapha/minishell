/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 18:26:30 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/18 20:13:06 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

void	expand_home_dir(char **dest)
{
	char	*aux;

	free(*dest);
	aux = ht_search(g_minishell.env, "HOME");
	*dest = ft_strdup(aux);
}
