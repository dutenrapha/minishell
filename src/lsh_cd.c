/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 21:02:09 by rdutenke          #+#    #+#             */
/*   Updated: 2021/09/18 20:13:26 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	lsh_cd(char **args)
{
	char	*home_dir;
	int		ret;

	home_dir = ht_search(g_minishell.env, "HOME");
	if (args[1] == NULL)
		ret = chdir(home_dir);
	else
		ret = chdir(args[1]);
	if (ret != 0)
		error_return("cd", NO_FILE_OR_DIR, 1);
	return (1);
}
