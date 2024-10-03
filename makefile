NAME    = minishell
CC      = cc
CFLAGS  = -Wall -Werror -Wextra -g3 -fsanitize=address

SRCS    = minishell_lyall.c utils/ft_strdup.c utils/list_stuff.c 

OBJ     = $(SRCS:.c=.o)

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lreadline -o $@

clean: 
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re