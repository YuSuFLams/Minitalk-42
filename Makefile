NAME_SER=server
NAME_CLI=client

NAME_SER_BONUS=server_bonus
NAME_CLI_BONUS=client_bonus


SERVER=server.c
CLIENT=client.c

SERVER_BONUS=server_bonus.c
CLIENT_BONUS=client_bonus.c

CC = cc

GSRC= minitalk_utils.c

SER=$(SERVER)
CLI=$(CLIENT)

SER_BONUS=$(SERVER_BONUS)
CLI_BONUS=$(CLIENT_BONUS)

M_SER = $(SER)
M_CLI = $(CLI)

B_SER = $(SER_BONUS)
B_CLI = $(CLI_BONUS)

BSRC=$(GSRC)


CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

all :$(NAME_SER) $(NAME_CLI)

bonus: $(NAME_CLI_BONUS) $(NAME_SER_BONUS)

$(NAME_SER) : $(M_SER) $(BSRC)
	$(CC) $(CFLAGS) $^ -o $@

$(NAME_CLI) : $(M_CLI) $(BSRC)
	$(CC) $(CFLAGS) $^ -o $@

$(NAME_SER_BONUS) : $(B_SER) $(BSRC)
	$(CC) $(CFLAGS) $^ -o $@

$(NAME_CLI_BONUS) : $(B_CLI) $(BSRC)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) *.o
fclean:
	$(RM) *.o $(NAME_SER) $(NAME_CLI) $(NAME_SER_BONUS) $(NAME_CLI_BONUS)

 
re: fclean all

.PHONY: all clean fclean all