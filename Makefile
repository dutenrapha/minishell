SRC_PATH = ./src
OBJ_PATH = ./obj
LIB_PATH = ./lib
LIBFT_PATH = ./lib/libft

CC = gcc
FLAGS = -Wall -Wextra -Werror
LIB_NAME = minishaell.a
LIBFT_NAME = libft.a
NAME = minishell
MAIN = main.c

LIB = $(LIB_PATH)/$(LIB_NAME)
LIBFT = $(LIBFT_PATH)/$(LIBFT_NAME)
SRC = $(notdir $(wildcard ./src/*.c))
OBJ=$(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))

all: config $(NAME)

clean:
	@make clean -C $(LIBFT_PATH)
	@rm -f $(OBJ_PATH)/*.o

fclean:	clean
	@rm -f $(LIB_PATH)/*.a
	@rm -f $(LIBFT_PATH)/*.a
	@rm -f $(NAME)
	@rm -f *.o
	@rm -fR *.dSYM
	@rm -fR obj

re: fclean all

config:
	@mkdir obj
$(NAME):	$(LIBFT) $(LIB)
	@$(CC) $(FLAGS) $(MAIN) -g $(LIB) $(LIBFT) -o $@

$(LIB): $(OBJ)
	@ar rcs $@ $(OBJ)

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c
	@$(CC) -g $(FLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_PATH)
