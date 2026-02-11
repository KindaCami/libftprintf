# Nombre de la librería final
NAME		= libftprintf.a

# Compilador y banderas (Mandatorios en 42)
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

# Lista de tus archivos fuente (Asegúrate de que los nombres coinciden)
SRC			= ft_printf.c \
			  conversion_manager.c \
			  ft_utils.c \
			  handlers_idu.c \
			  handlers_hex.c \
			  handlers_scpper.c

# Convierte los .c en .o automáticamente
OBJ			= $(SRC:.c=.o)

# Regla principal
all:		$(NAME)

# Crea la librería estática (.a)
# ar: archiver
# r: reemplaza archivos existentes
# c: crea la librería si no existe
# s: crea un índice del contenido (hace que sea más rápido buscar funciones)
$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)

# Regla para compilar los .c en .o
%.o: %.c
			$(CC) $(CFLAGS) -c $< -o $@

# Limpia los archivos objeto (.o)
clean:
			$(RM) $(OBJ)

# Limpia los objetos y la librería (.a)
fclean:		clean
			$(RM) $(NAME)

# Re-compila todo desde cero
re:			fclean all
bonus:		all

# Indica que estas reglas no son archivos físicos
.PHONY:		all clean fclean re