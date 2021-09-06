SRC_PATH = ./src
OBJ_PATH = ./obj
LIB_PATH = ./lib
LIB_TESTS = ./tests
LIBFT_PATH = ./lib/libft

CC = clang
FLAGS = -Wall -Wextra -Werror -g -fsanitize=address
LIB_NAME = minishaell.a
LIBFT_NAME = libft.a
TESTS_NAME = executable
NAME = minishell

MAIN = main.c
TESTS_SRC = executable.c

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
	@rm -f $(LIB_TESTS)/$(TESTS_NAME)
	@rm -f $(NAME)
	@rm -f *.o
	@rm -fR *.dSYM
	@rm -fR obj

re: fclean all run

config:
	$(CC) $(FLAGS) -L. -lreadline $(LIB_TESTS)/$(TESTS_SRC) -o $(LIB_TESTS)/$(TESTS_NAME)
	@mkdir -p obj

run:
	@clear
	@./$(NAME)

install:
	sudo apt-get install libreadline-dev

$(NAME):	$(LIBFT) $(LIB)
	@$(CC) $(FLAGS) -L. -lreadline $(MAIN) -g $(LIB) $(LIBFT) -o $@

$(LIB): $(OBJ)
	@ar rcs $@ $(OBJ)

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c
	@$(CC) -g $(FLAGS) -c $< -o $@

$(LIBFT):
	@make -C $(LIBFT_PATH)
