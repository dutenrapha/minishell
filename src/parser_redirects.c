/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 22:07:36 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/14 18:13:36 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

static void	redirect_output(char *filename, int flags)
{
	int	fd_file;

	fd_file = open(filename, flags, 0777);
	if (fd_file == -1)
		error_return("redirect", strerror(errno), 1);
	else
	{
		dup2(fd_file, 1);
		close(fd_file);
	}
}

static void	redirect_input(char *filename, int flags)
{
	int	fd_file;

	fd_file = open(filename, flags);
	if (fd_file == -1)
		error_return("redirect", strerror(errno), 1);
	else
	{
		dup2(fd_file, 0);
		close(fd_file);
	}
}

void	check_redirects(t_token *current, t_token *end, int *save_std_fd)
{
	(void)save_std_fd;//
	while (current != end)
	{
		printf("[type = %d]  [%s]\n", current->type, current->value);
		if (!current->next)
			break;
		if (current->type == T_OREDIRECT && current->next->type == T_WORD)
			redirect_output(current->next->value, O_WRONLY | O_CREAT | O_TRUNC);
		else if (current->type == T_IREDIRECT && current->next->type == T_WORD)
			redirect_input(current->next->value, O_RDONLY | O_CREAT);
		else if (current->type == T_OAPPEND && current->next->type == T_WORD)
			redirect_output(current->next->value, O_WRONLY | O_CREAT | O_APPEND);
		// else if (current->type == T_HERE_DOC && current->next->type == T_WORD)
		// 	here_doc_input(current->next->value, save_std_fd);
		current = current->next;
	}
}

