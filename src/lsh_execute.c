/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_execute.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 22:58:36 by rdutenke          #+#    #+#             */
/*   Updated: 2021/05/10 21:54:17 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int lsh_execute(char **args)
{
	int		i;
	char	*builtin_str[2];
	int		(*builtin_func[2]) (char **);

	builtin_str[0] = "cd";
	builtin_str[1] = "exit";
	builtin_func[0] = &lsh_cd;
	builtin_func[1] = &lsh_exit;
	if (args[0] == NULL)
		return (1);
	i = 0;
	while (i < LSH_NUM_BUILTINS)
	{
		if (ft_strncmp(args[0], builtin_str[i], ft_strlen(args[0])) == 0)
		{
			return (*builtin_func[i])(args);
		}
		i++;
	}
	return (lsh_launch(args));
}