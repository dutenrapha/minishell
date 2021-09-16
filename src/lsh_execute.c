/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 22:58:36 by rdutenke          #+#    #+#             */
/*   Updated: 2021/09/16 17:07:59 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

// static bool	get_all_possible_paths(char **all_paths, char **args)
static bool	get_all_possible_paths(char **all_paths)
{
	*all_paths = ht_search(g_minishell.env, "PATH");
	if (!*all_paths)
	{
		// *all_paths = hashmap_search(g_minishell.local_vars, "PATH");
		// if (!*all_paths)
		// {
		// 	error_message(args[0], NO_FILE_OR_DIR, 127);
		// 	return (FALSE);
		// }
		return (FALSE);
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

	//if (!args[0] || (!get_all_possible_paths(&all_paths, args)))
	if (!args[0] || (!get_all_possible_paths(&all_paths)))
		return ;
	args_with_path = get_absolute_path(args[0], all_paths);
	// if (!args_with_path)
	// {
	// 	error_message(args[0], NOT_FOUND, 127);
	// }
	free(args[0]);
	args[0] = args_with_path;
}


int	lsh_execute(char **args)
{
	int		i;
	char	*builtin_str[LSH_NUM_BUILTINS];
	int		(*builtin_func[LSH_NUM_BUILTINS])(char **);

	if (check_is_local_var(args) == TRUE)
	{
		set_local_var(args);
		args = (args + 1);
	}
	builtin_str[0] = "m_cd";
	builtin_str[1] = "m_exit";
	builtin_str[2] = "m_pwd";
	builtin_str[3] = "m_env";
	builtin_str[4] = "m_set";
	builtin_str[5] = "m_export";
	builtin_str[6] = "m_unset";
	builtin_func[0] = &lsh_cd;
	builtin_func[1] = &lsh_exit;
	builtin_func[2] = &lsh_pwd;
	builtin_func[3] = &lsh_env;
	builtin_func[4] = &lsh_set;
	builtin_func[5] = &lsh_export;
	builtin_func[6] = &lsh_unset;
	if (args[0] == NULL)
		return (1);
	i = 0;
	while (i < LSH_NUM_BUILTINS)
	{
		if (ft_strncmp(args[0], builtin_str[i], ft_strlen(args[0])) == 0)
		{
			return ((*builtin_func[i])(args));
		}
		i++;
	}
	add_path(args);
	return (lsh_launch(args));
}
