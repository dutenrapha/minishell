/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 22:58:36 by rdutenke          #+#    #+#             */
/*   Updated: 2021/09/13 14:20:45 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static bool	check_is_local_var(char **args)
{
	char	*aux;
	bool	have_equal;
	bool	have_space;

	aux = args[0];
	have_equal = FALSE;
	have_space = FALSE;
	if (ft_strchr(aux, '='))
		have_equal = TRUE;
	if (ft_strchr(aux, SPACE))
		have_space = TRUE;
	if (have_equal && !have_space)
		return (TRUE);
	return (FALSE);
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
	builtin_func[0] = &lsh_cd;
	builtin_func[1] = &lsh_exit;
	builtin_func[2] = &lsh_pwd;
	builtin_func[3] = &lsh_env;
	builtin_func[4] = &lsh_set;
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
	return (lsh_launch(args));
}
