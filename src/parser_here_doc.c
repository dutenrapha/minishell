/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 10:36:49 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/18 15:08:10 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/header.h"

#define TMP_FILE	"/tmp/minishell_temp_file"

static int	create_tmp_file(void)
{
	int	fd;

	fd = open(TMP_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		error_return("redirect", strerror(errno), 1);
	return (fd);
}

static void	get_heredoc_input(int tmp_fd, char *eof)
{
	char	*input;

	signal(SIGINT, int_here_doc);
	while (TRUE)
	{
		input = readline("> ");
		if (!input)
		{
			error_return("Warning", "here-document delimited by EOF", 0);
			close(tmp_fd);
			exit(0);
		}
		if (ft_strcmp(input, eof))
			ft_putendl_fd(input, tmp_fd);
		else
		{
			close(tmp_fd);
			free(input);
			break ;
		}
		free(input);
	}
	exit(0);
}

static void	clear_tmp_file_input(void)
{
	int		tmp_fd;

	tmp_fd = open(TMP_FILE, O_WRONLY | O_TRUNC, 0777);
	close(tmp_fd);
}

static void	make_tmp_file_input(void)
{
	int		tmp_fd;

	tmp_fd = open(TMP_FILE, O_RDONLY);
	unlink(TMP_FILE);
	dup2(tmp_fd, 0);
	close(tmp_fd);
}

void	here_doc_input(char *eof, int *save_std_fd)
{
	int	tmp_fd;
	int	save_fd_out;
	int	pid;
	int	status;

	tmp_fd = create_tmp_file();
	if (tmp_fd == -1)
		return ;
	save_fd_out = dup(1);
	dup2(save_std_fd[1], STDOUT_FILENO);
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == 0)
		get_heredoc_input(tmp_fd, eof);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status) && WEXITSTATUS(status) == 130)
	{
		clear_tmp_file_input();
		g_minishell.erro = 130;
	}
	make_tmp_file_input();
	dup2(save_fd_out, STDOUT_FILENO);
	close(save_fd_out);
}
