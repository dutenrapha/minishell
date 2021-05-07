# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rdutenke <rdutenke@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/27 12:40:11 by rdutenke          #+#    #+#              #
#    Updated: 2021/04/19 14:58:33 by rdutenke         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

COMPI = gcc

FUNCTIONS = ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memcmp.c\
		ft_memchr.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_strncmp.c \
		ft_isalpha.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
		ft_strtrim.c ft_split.c ft_countword.c ft_shift.c ft_shift2.c ft_strmapi.c	 \
		ft_putendl_fd.c ft_putnbr_fd.c ft_printf.c ft_check_flag.c ft_int_len.c ft_print_x.c ft_itoa_base.c ft_print_xup.c \
		ft_print_p.c ft_print_u.c ft_print_int.c ft_print_char.c ft_print_str.c\
		ft_padding.c ft_itoa_hex.c ft_flag_width.c ft_get_width.c ft_flag_minus.c\
		ft_flag_zeros.c ft_flag_none.c ft_flag_asterisk.c ft_set_conversion.c ft_check_precision.c\
		ft_flag_precision.c ft_putchar_fd.c ft_strlen.c ft_calloc.c ft_substr.c ft_atoi.c ft_strchr.c \
		ft_putstr_fd.c ft_strdup.c ft_memset.c ft_strjoin.c ft_itoa.c ft_strrchr.c ft_isdigit.c ft_print_padding.c get_next_line.c\

FUNCTIONS_O = $(subst .c,.o,$(FUNCTIONS))

FUNCTIONSB = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

FUNCTIONSB_O = $(subst .c,.o,$(FUNCTIONSB))

all: $(NAME)

$(NAME):
	@$(COMPI) -Wall -Wextra -Werror -c $(FUNCTIONS)
	@ar rc $(NAME) $(FUNCTIONS_O)
	@ranlib $(NAME)

clean:
	@/bin/rm -f *.o

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

debug:	fclean all
	@$(COMPI) -Wall -Wextra -Werror -g main5.c -L. -lft -lbsd
	@./a.out
run:
	@$(COMPI) -Wall -Wextra -Werror main.c -L. -lft -lbsd
	@./a.out
so:
	@$(COMPI) -fPIC -c $(FUNCTIONS)
	@$(COMPI) -shared -o libft.so $(FUNCTIONS_O)

bonus: $(NAME)
	$(COMPI) -Wall -Werror -Wextra -c $(FUNCTIONSB)
	ar rc $(NAME) $(FUNCTIONSB_O)
	ranlib $(NAME)
	@$(COMPI) -Wall -Wextra -Werror -g mainbonus.c -L. -lft -lbsd
	@./a.out
