/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 22:58:36 by rdutenke          #+#    #+#             */
/*   Updated: 2021/09/18 16:52:20 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static bool	get_all_possible_paths(char **all_paths)
{
	*all_paths = ht_search(g_minishell.env, "PATH");
	if (!*all_paths)
	{
		*all_paths = ht_search(g_minishell.local_var, "PATH");
		return (FALSE);
	}
	return (TRUE);
}

static bool	check_is_local_var(char **args)
{
	char	*aux;
	int		i;
	bool	have_equal;
	bool	have_space;

	i = 0;
	aux = args[0];
	have_equal = FALSE;
	have_space = FALSE;
	if (!ft_strchr(aux, '='))
		return (FALSE);
	while (aux[i] != '=')
	{
		if (aux[i] == SPACE || aux[i] == '?')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static void	add_path(char **args)
{
	char	*args_with_path;
	char	*all_paths;

	if (!args[0] || (!get_all_possible_paths(&all_paths)))
		return ;
	args_with_path = get_absolute_path(args[0], all_paths);
	if (args_with_path != NULL)
	{
		free(args[0]);
		args[0] = args_with_path;
	}
}

int	lsh_execute(char **args)
{
	int	i;

	i = 0;
	if (check_is_local_var(args) == TRUE)
	{
		set_local_var(args);
		args = (args + 1);
	}
	if (args[0] == NULL)
		return (1);
	i = check_is_builtin(args[0]);
	if (i >= 0)
		return (execute_builtin(i, args));
	add_path(args);
	return (lsh_launch(args));
}
