NAME = pipex
LIBFT = libft.a

LIBFT_PATH = ./libs/libft/
INCLUDES = -I ./includes
FILES = pipex.c pipex_utils.c error_utils.c pipex_cmds_handler.c \
		pipex_processes.c pipex_process_utils.c
SRC = $(FILES)
OBJECTS = $(SRC:%.c=%.o)
SRC_ALL = $(addprefix ./src/mandatory/, $(FILES))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	make --no-print-directory -C $(LIBFT_PATH) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -I $(HEADER) -L $(LIBFT_PATH)$(LIBFT)

$(OBJECTS): $(SRC_ALL)
	$(CC) $(CFLAGS) $(INCLUDES) -c $(SRC_ALL)

clean:
	make --no-print-directory -C $(LIBFT_PATH) fclean
	$(RM) $(OBJECTS)

fclean: clean
	echo cleaning!
	make --no-print-directory -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)
	echo done!

re: fclean all

.PHONY: all clean fclean re