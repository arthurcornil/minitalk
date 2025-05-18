CC=cc

CFLAGS=-Wall -Wextra -Werror

SERVER_SRCS=server.c

CLIENT_SRCS=client.c

NAME=minitalk

$(NAME): all

all:
	$(CC) $(CFLAGS) $(SERVER_SRCS) -o server
	$(CC) $(CFLAGS) $(CLIENT_SRCS) -o client
