/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 19:29:23 by rdutenke          #+#    #+#             */
/*   Updated: 2021/04/19 14:58:03 by rdutenke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>

# define DIGITO			"*123456789"
# define DEC_BASE		"0123456789"
# define HEX_BASE_L		"0123456789abcdef"
# define HEX_BASE_U		"0123456789ABCDEF"
# define CONVERSIONS	"cspdiuxX%nfge"
# define BREAKS			"cspdiuxX%"
# define FLAGS			"-0.*# +lh"
# define BUFFER_SIZE 100

typedef struct s_parms_itoa
{
	char		*itoa;
	long int	n_orig;
	int			resto;
	int			i;
	int			passo;
}				t_pf;

typedef struct s_params
{
	va_list		ap;
	int			len_c;
	char		*flag;
	char		*str;
	char		*v_str;
	void		*v_p;
	int			asterisk;
	int			v_ast;
	int			v_char;
	char		v_c;
	intmax_t	v_int;
	char		conversion;
	size_t		width;
	int			precision;
	int			len;
	int			slen;
	int			i;
}				t_ptf;

typedef struct s_listt
{
	void			*content;
	struct s_list	*next;
}				t_listt;

void			ft_bzero(void *s, int nbyte);
void			*ft_memcpy(void *str1, const void *str2, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *str1, const void *str2, size_t n);
void			*ft_memchr(const void *str, int c, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
char			*ft_strtrim(char const *s1, char const *set);
int				ft_countword(char const *s1, char c);
char			**ft_split(char const *s, char c);
char			ft_shift(unsigned int i, char s);
char			ft_shift2(unsigned int i, char s);
char			*ft_strmapi(char const *s, char(*f)(unsigned int, char));
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_listt			*ft_lstnew_(void *content);
void			ft_lstadd_front(t_listt **lst, t_listt *new);
int				ft_lstsize_(t_listt *lst);
t_listt			*ft_lstlast(t_listt *lst);
void			ft_lstadd_back_(t_listt **lst, t_listt *new);
void			ft_lstdelone(t_listt *lst, void (*del)(void*));
void			ft_lstclear_(t_listt **lst, void (*del)(void*));
void			ft_lstiter(t_listt *lst, void (*f)(void *));
t_listt			*ft_lstmap(t_listt *lst, void *(*f)(void *),
					void (*del)(void *));
int				ft_printf(const char *str, ...);
void			ft_check_flag(t_ptf *parms);
int				ft_int_len(intmax_t d);
void			ft_print_x(t_ptf *parms);
char			*ft_itoa_base(uintmax_t nb, char *base);
void			ft_print_xup(t_ptf *parms);
void			ft_print_p(t_ptf *parms);
void			ft_print_u(t_ptf *parms);
void			ft_print_int(t_ptf *parms);
void			ft_print_char(t_ptf *parms);
void			ft_print_str(t_ptf *parms);
void			ft_padding(char type, t_ptf *parms);
char			*ft_itoa_hex(uint32_t nb, char *base);
void			ft_flag_width(t_ptf *parms);
void			ft_get_width(t_ptf *parms, int k);
void			ft_flag_minus(t_ptf *parms);
void			ft_flag_zeros(t_ptf *parms);
void			ft_flag_none(t_ptf *parms);
void			ft_flag_asterisk(t_ptf *parms);
void			ft_set_conversion(t_ptf *parms);
void			ft_check_precision(t_ptf *parms);
void			ft_flag_precision(t_ptf *parms);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
size_t			ft_strlen(const char *s);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_atoi(const char *nptr);
char			*ft_strchr(const char *s, int c);
char			*ft_strdup(const char *s);
void			*ft_memset(void *str, int c, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_itoa(int n);
char			*ft_strrchr(const char *s, int c);
int				ft_isdigit(int c);
void			ft_print_padding(int size, char c);
int				get_next_line(int fd, char **line);
int				ft_memcmp(const void *str1, const void *str2, size_t n);
#endif
