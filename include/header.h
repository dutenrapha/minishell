/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:20:32 by rdutenke          #+#    #+#             */
/*   Updated: 2021/09/18 12:59:41 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define LSH_RL_BUFSIZE 1024
# define LSH_NUM_BUILTINS 8
# define LSH_TOK_DELIM ' '
# define NOT_FOUND "command not found."
# define NO_FILE_OR_DIR "no such file or directory."
# define LOCAL_HASHTABLE_SIZE 50
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <error.h>
# include <sys/wait.h>
# include "../lib/libft/libft.h"
# include "hashtable.h"
# include "tokenizer.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>

typedef struct s_read
{
	int		bufsize;
	int		position;
	char	*buffer;
	int		c;
}						t_read;

typedef struct s_minishell
{
	t_hashtable	*env;
	t_hashtable	*local_var;
	int			erro;
}				t_minishell;

/*
** GLOBAL VARIABLE
*/
t_minishell	g_minishell;

void		lsh_loop(void);
int			ft_getchar(void);
char		*lsh_read_line(void);
void		*ft_realloc(void *ptr, size_t size);
int			lsh_cd(char **args);
int			lsh_exit(char **args);
int			lsh_pwd(char **args);
int			lsh_execute(char **args);
int			lsh_launch(char **args);
int			lsh_env(char **args);
t_hashtable	*env_to_hashtable(char **env);
void		loop_signals(void);
void		exec_signals(void);
char		*get_absolute_path(char *cmd, char *path_variable);
void		free_2d_array(char **ptr);
void		set_local_var(char **args);
int			lsh_set(char **args);
int			lsh_export(char **args);
int			lsh_unset(char **args);
void		error_return(char *input, char *error_message, int status);
int			lsh_echo(char **args);
#endif