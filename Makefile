CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes -I./libft

SRC = source/ft_printf.c source/ft_solve_o.c source/ft_solve_hex.c \
      source/ft_solve_percent.c source/ft_solve_char.c source/ft_solve_di.c \
      source/ft_solve_pointer.c source/ft_solve_string.c source/ft_solve_uint.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	ar rcs $(NAME) $(OBJ)
	libtool -static -o $(NAME) $(NAME) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	@$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

test: all
	$(CC) $(CFLAGS) $(INCLUDES) test.c $(NAME) -o test_program

test_clean:
	rm -f test_program

test_run: test
	./test_program
