/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:20:32 by rdutenke          #+#    #+#             */
/*   Updated: 2021/09/04 15:07:48 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define LSH_RL_BUFSIZE 1024
#define LSH_NUM_BUILTINS 4
#define LSH_TOK_DELIM ' '
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <error.h>
# include <unistd.h>
# include <sys/wait.h>
# include "../lib/libft/libft.h"
# include "hashtable.h"
# include "tokenizer.h"
#include <readline/readline.h>
#include <readline/history.h>

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
}				t_minishell;

/*
** GLOBAL VARIABLE
*/

t_minishell	g_minishell;

void	lsh_loop(void);
int		ft_getchar(void);
char	*lsh_read_line(void);
void	*ft_realloc(void *ptr,size_t size);
int		lsh_cd(char **args);
int		lsh_exit(char **args);
int		lsh_pwd(char **args);
int		lsh_execute(char **args);
int		lsh_launch(char **args);
int		lsh_env(char **args);
t_hashtable	*env_to_hashtable(char **env);
#endif