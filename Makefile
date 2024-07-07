CC = cc 
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rc
NAME = libftprintf.a
SRCS = ft_printf.c ft_putnbr_s.c ft_print.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar $(ARFLAGS) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	
fclran:
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re