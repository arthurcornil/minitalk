CC=cc

CFLAGS=-Wall -Wextra -Werror

SERVER_SRCS=server.c

CLIENT_SRCS=client.c

PRINTF_DIR=./ft_printf/
PRINTF_LIB=libftprintf.a

NAME=minitalk

RM=rm -f

$(NAME): all

all:
	make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(SERVER_SRCS) utils.c $(PRINTF_DIR)$(PRINTF_LIB) -o server
	$(CC) $(CFLAGS) $(CLIENT_SRCS) utils.c $(PRINTF_DIR)$(PRINTF_LIB) -o client

clean:
	make clean -C $(PRINTF_DIR)

fclean:
	make fclean -C $(PRINTF_DIR)
	$(RM) server client
