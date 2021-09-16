/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:25:25 by rdutenke          #+#    #+#             */
/*   Updated: 2021/09/16 16:49:00 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static char	*get_possible_path(char *envpath, char *args)
{
	char	*path;
	char	*temp;

	if (ft_strncmp(envpath, args, ft_strlen(envpath)) == 0)
	{
		path = ft_strdup(args);
	}
	else
	{
		temp = ft_strjoin(envpath, "/");
		path = ft_strjoin(temp, args);
		free(temp);
	}
	return (path);
}

static bool	is_executable(char *path)
{
	struct stat	buffer;

	if (stat(path, &buffer) != 0)
		return (FALSE);
	if ((buffer.st_mode & S_IFMT) == S_IFDIR)
		return (FALSE);
	if ((buffer.st_mode & S_IXUSR))
		return (TRUE);
	return (FALSE);
}

char	*get_absolute_path(char *args, char *path_variable)
{
	char		**all_paths;
	char		*path;
	int			i;

	i = 0;
	all_paths = ft_split(path_variable, ':');
	while (all_paths && all_paths[i])
	{
		path = get_possible_path(all_paths[i], args);
		if (is_executable(path))
			break ;
		free(path);
		path = NULL;
		i++;
	}
	free_2d_array(all_paths);
	return (path);
}
