/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsh_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 18:27:01 by rdutenke          #+#    #+#             */
/*   Updated: 2021/05/11 20:30:18 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

int	lsh_pwd(char **args)
{
	char	cwd[1024];

	if (args[0] == NULL)
		args[0] = args[0];
	getcwd(cwd, sizeof(cwd));
	ft_printf("%s\n", cwd);
	return (1);
}
