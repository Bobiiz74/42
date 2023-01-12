SRC = 	main.c \

CC = gcc

CFLAGS = -Wall -Werror -Wextra

NAME = fdf

OBJ = $(SRC:.c=.o)

all: $(NAME)

.c .o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

RM = rm -f

# Compile la lib
DIR_LIBFT = libft/
LIBFT_INC = -I $(DIR_LIBFT)
LIBFT = $(DIR_LIBFT)libft.a
FT_LINK = -L $(DIR_LIBFT) -l ft

# Compile la MiniLBX
DIR_MLX = mlx_macos/
MLX_LNK = -L $(DIR_MLX) -l mlx -framework OpenGL -framework AppKit
MLX_INC = -I ${DIR_MLX}
MLX =   ${DIR_MLX}libmlx.a

# Link la lib, la mlx et ft_printf
LIBS = $(FT_LINK)	$(MLX_LNK)		

# Make la lib
$(LIBFT):
		$(MAKE) -sC $(@D)

# Make la mlx
$(MLX):
		$(MAKE) -sC $(@D)

# Compile tout, sous le nom fdf
${NAME}:	${LIBFT}	${MLX}		${OBJ}
			${CC}	${OBJ}	$(LIBS) -o ${NAME}

clean:	
		$(RM) $(OBJ)
		make fclean -C ./libft
		make clean -C ./mlx_macos

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re
