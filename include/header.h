/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 21:20:32 by rdutenke          #+#    #+#             */
/*   Updated: 2021/05/11 15:33:35 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define LSH_RL_BUFSIZE 10
#define LSH_NUM_BUILTINS 3
#define LSH_TOK_DELIM ' '
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <error.h>
# include <sys/wait.h>
# include "../lib/libft/libft.h"

typedef struct s_read
{
	int		bufsize;
	int		position;
	char	*buffer;
	int		c;
}						t_read;

void	lsh_loop(void);
int		ft_getchar(void);
char	*lsh_read_line(void);
void	*ft_realloc(void *ptr,size_t size);
int		lsh_cd(char **args);
int		lsh_exit(char **args);
int		lsh_execute(char **args);
int		lsh_launch(char **args);
#endif