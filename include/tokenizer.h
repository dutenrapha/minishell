/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:02:27 by aalcara-          #+#    #+#             */
/*   Updated: 2021/09/14 18:07:40 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
#define TOKENIZER_H
# include <unistd.h>
# include <stdbool.h>

# define TRUE 1
# define FALSE 0
# define S_QUOTE '\''
# define D_QUOTE '\"'
# define LESS '<'
# define GREATER '>'
# define SPACE ' '
# define C_NULL '\0'
# define PIPE '|'

typedef enum e_state
{
	S_GENERAL,
	S_SQUOTE,
	S_DQUOTE
} t_state;

typedef enum e_type
{
	T_UNDEFINED,
	T_WORD,
	T_PIPE,
	T_IREDIRECT,
	T_OREDIRECT,
	T_HERE_DOC,
	T_OAPPEND
}t_type;

typedef struct s_token
{
	int				type;
	char			*value;
	struct s_token	*next;
}t_token;

typedef struct s_tokendata
{
	size_t		i;
	size_t		j;
	const char	*input;
	t_state		state;
	t_type		type;
	char 		buffer[1000];
}t_tokendata;

t_token	*tokenizer(char *input);
void	get_token(t_tokendata *tk, t_token **tokens);
void	lexer(t_token *token);
void	free_tokens(t_token **tokens);
//utils
char	*expand_variable(char *str, char *dest, int *i, int len);
char	*expand_word(char *key, int len);
bool	check_is_closed(char *str, char quote);
char	*ft_strjoinrealloc(char *s1, char *s2, int len);
bool	special_token(t_token *token, const char *str);

//parser
void	parse_tokens(t_token *tokens);
void	command_parser(t_token *tokens, t_token *pipe, int *last_pipe_in);
char	**create_command_array(t_token *start, t_token *pipe);
void	check_redirects(t_token *current, t_token *end, int *save_std_fd);
#endif