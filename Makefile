NAME_SER=server
NAME_CLI=client

NAME_SER_BONUS=server_bonus
NAME_CLI_BONUS=client_bonus

CC = cc

RM = rm -rf

CFLAGS	= -Wall -Wextra -Werror

SRCS = client.c server.c minitalk_utils.c

SRCS_BONUS = client_bonus.c server_bonus.c minitalk_utils.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME_CLI) $(NAME_SER)

bonus: $(NAME_CLI_BONUS) $(NAME_SER_BONUS)

$(NAME_CLI): client.o minitalk_utils.o
	@$(CC) $(CFLAGS) $^ -o $@

$(NAME_SER): server.o minitalk_utils.o
	@$(CC) $(CFLAGS) $^ -o $@

$(NAME_CLI_BONUS): client_bonus.o minitalk_utils.o
	@$(CC) $(CFLAGS) $^ -o $@

$(NAME_SER_BONUS): server_bonus.o minitalk_utils.o
	@$(CC) $(CFLAGS) $^ -o $@

%.o: %.c minitalk.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) *.o

fclean: clean
	@$(RM) *.o $(NAME_CLI) $(NAME_SER) $(NAME_CLI_BONUS) $(NAME_SER_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus