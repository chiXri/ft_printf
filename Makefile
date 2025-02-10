# Definir el compilador y las banderas
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes -I./libft

# Archivos fuente para ft_printf
SRC = source/ft_printf.c source/ft_solve_o.c source/ft_solve_hex.c \
      source/ft_solve_percent.c source/ft_solve_char.c source/ft_solve_di.c \
      source/ft_solve_pointer.c source/ft_solve_string.c source/ft_solve_uint.c
OBJ = $(SRC:.c=.o)
NAME = libftprintf.a

# Ruta y archivo de la librería libft
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Regla principal para compilar todo
all: $(LIBFT) $(NAME)

# Compilar libft
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Compilar ft_printf
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Compilar los archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Limpiar archivos .o de ft_printf y libft
clean:
	rm -f $(OBJ)
	@$(MAKE) clean -C $(LIBFT_DIR)

# Limpiar todo, incluyendo las librerías generadas
fclean: clean
	rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_DIR)

# Volver a compilar todo desde cero
re: fclean all

# Compilar y ejecutar el archivo de prueba test.c
test: all
	$(CC) $(CFLAGS) $(INCLUDES) test.c $(NAME) $(LIBFT) -o test_program

# Limpiar solo el ejecutable de prueba
test_clean:
	rm -f test_program

# Ejecutar las pruebas
test_run: test
	./test_program
