/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_execute_builtin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:28:35 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/18 16:50:46 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	check_is_builtin(char *arg)
{
	int		i;
	char	*builtin_str[LSH_NUM_BUILTINS];

	i = 0;
	builtin_str[0] = "cd";
	builtin_str[1] = "exit";
	builtin_str[2] = "pwd";
	builtin_str[3] = "env";
	builtin_str[4] = "export";
	builtin_str[5] = "unset";
	builtin_str[6] = "echo";
	while (i < LSH_NUM_BUILTINS)
	{
		if (ft_strcmp(arg, builtin_str[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	execute_builtin(int i, char **args)
{
	int		(*builtin_func[LSH_NUM_BUILTINS])(char **);

	builtin_func[0] = &lsh_cd;
	builtin_func[1] = &lsh_exit;
	builtin_func[2] = &lsh_pwd;
	builtin_func[3] = &lsh_env;
	builtin_func[4] = &lsh_export;
	builtin_func[5] = &lsh_unset;
	builtin_func[6] = &lsh_echo;
	return ((*builtin_func[i])(args));
}
