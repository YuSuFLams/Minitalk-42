NAME_SER=server
NAME_CLI=client

NAME_SER_BONUS=server_bonus
NAME_CLI_BONUS=client_bonus

SERVER=server.c
CLIENT=client.c

SERVER_BONUS=server_bonus.c
CLIENT_BONUS=client_bonus.c

M_HEADER = minitalk.h
B_HEADER = minitalk_bonus.h

GSRC= minitalk_utils.c

CFLAGS = -Wall -Werror -Wextra

CC = cc

RM = rm -rf

all: $(NAME_CLI) $(NAME_SER)

$(NAME_CLI) : $(CLIENT) $(M_HEADER)
		$(CC) $(CFLAGS) $(CLIENT) $(GSRC) -o $(NAME_CLI)
$(NAME_SER) : $(SERVER) $(M_HEADER)
		$(CC) $(CFLAGS) $(SERVER) $(GSRC) -o $(NAME_SER)

bonus: $(NAME_CLI_BONUS) $(NAME_SER_BONUS)

$(NAME_CLI_BONUS) : $(CLIENT_BONUS) $(B_HEADER)
		$(CC) $(CFLAGS) $(CLIENT_BONUS) $(GSRC) -o $(NAME_CLI_BONUS)
$(NAME_SER_BONUS) : $(SERVER_BONUS) $(B_HEADER)
		$(CC) $(CFLAGS) $(SERVER_BONUS) $(GSRC) -o $(NAME_SER_BONUS)
fclean:
	$(RM) $(NAME_CLI) $(NAME_SER) $(NAME_CLI_BONUS) $(NAME_SER_BONUS)

re: fclean all bonus
