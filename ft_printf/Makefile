CC=cc

CFLAGS=-Wall -Wextra -Werror

RM=rm -rf

LIBFT_DIR=./libft/

SRCS_DIR=./srcs/

SRCS=$(SRCS_DIR)ft_fts.c\
	 $(SRCS_DIR)ft_get_format.c\
	 $(SRCS_DIR)ft_print_char.c\
	 $(SRCS_DIR)ft_print_uint.c\
	 $(SRCS_DIR)ft_print_ptr.c\
	 $(SRCS_DIR)ft_print_hex.c\
	 $(SRCS_DIR)ft_print_int.c\
	 $(SRCS_DIR)ft_print_str.c\
	 $(SRCS_DIR)ft_printf.c

OBJS=${SRCS:.c=.o}
BOBJS=${BSRCS:.c=.o}

NAME=libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) 
	@make -C $(LIBFT_DIR)
	@cp -u $(LIBFT_DIR)/libft.a ./libftprintf.a
	ar rc $(NAME) $(OBJS)

clean: 
	$(RM) $(OBJS) $(BOBJS)
	@make fclean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean clean re
