/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 22:58:36 by rdutenke          #+#    #+#             */
/*   Updated: 2021/05/11 20:29:37 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	lsh_execute(char **args)
{
	int		i;
	char	*builtin_str[LSH_NUM_BUILTINS];
	int		(*builtin_func[LSH_NUM_BUILTINS])(char **);

	builtin_str[0] = "m_cd";
	builtin_str[1] = "m_exit";
	builtin_str[2] = "m_pwd";
	builtin_func[0] = &lsh_cd;
	builtin_func[1] = &lsh_exit;
	builtin_func[2] = &lsh_pwd;
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
