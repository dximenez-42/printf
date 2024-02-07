NAME = libftprintf.a
LIBNAME = ft_printf.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
	  ft_printf_args.c \
	  ft_printf_utils.c

OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ) $(LIBNAME)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all