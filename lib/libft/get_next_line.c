/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 21:43:07 by rdutenke          #+#    #+#             */
/*   Updated: 2020/08/27 14:24:59 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_clear_memory(int len_line, char **memory)
{
	char	*temp;
	int		end;

	end = 0;
	if (ft_strchr(*memory, '\n') != NULL)
		end = ft_strchr(*memory, '\0') - ft_strchr(*memory, '\n') - 1;
	if (end >= 1)
	{
		temp = ft_strdup(*memory);
		free(*memory);
		*memory = NULL;
		if (temp[len_line] == '\n')
			*memory = ft_substr(temp, len_line + 1, end);
		else
			*memory = NULL;
		free(temp);
	}
	else
	{
		free(*memory);
		*memory = NULL;
	}
}

static char	*ft_set_next_line(char **memory)
{
	char	*line;
	int		end;

	if (*memory == NULL)
	{
		line = ft_strdup("");
		return (line);
	}
	end = 0;
	if (ft_strchr(*memory, '\n') == NULL)
	{
		end = ft_strlen(*memory);
	}
	else
	{
		end = ft_strchr(*memory, '\0') - ft_strchr(*memory, '\n');
		end = ft_strlen(*memory) - end;
	}
	line = NULL;
	line = ft_substr(*memory, 0, end);
	return (line);
}

static void	ft_add(char *buf, char **memory)
{
	char	*temp;

	temp = NULL;
	if (*memory == NULL)
	{
		*memory = ft_strdup(buf);
	}
	else
	{
		temp = ft_strdup(*memory);
		free(*memory);
		*memory = NULL;
		*memory = ft_strjoin(temp, buf);
		free(temp);
	}
}

static int	ft_aux(int size, int fd, char *buf, char **memory)
{
	int	i;

	if (size > 0)
	{
		ft_add(buf, &*memory);
		while (size > 0 && ft_strchr(buf, '\n') == NULL)
		{
			i = -1;
			while (++i < BUFFER_SIZE + 1)
				buf[i] = '\0';
			size = read(fd, buf, BUFFER_SIZE);
			if (size > 0)
				ft_add(buf, &*memory);
		}
	}
	return (size);
}

int	get_next_line(int fd, char **line)
{
	int				size;
	char			buf[BUFFER_SIZE + 1];
	static char		*memory;
	int				i;

	i = -1;
	size = -1;
	if (BUFFER_SIZE <= 0 || fd < 0 || line == NULL)
		return (-1);
	if (ft_strchr(memory, '\n') == NULL)
	{
		while (++i < BUFFER_SIZE + 1)
			buf[i] = '\0';
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
			return (-1);
		size = ft_aux(size, fd, buf, &memory);
	}
	*line = ft_set_next_line(&memory);
	ft_clear_memory(ft_strlen(*line), &memory);
	if (size == 0 && ft_strlen(memory) == 0)
		return (0);
	else
		return (1);
}
