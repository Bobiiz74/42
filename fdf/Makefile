SRCS	= main.c \

NAME	= fdf

CC	= gcc

RM	= rm -f

AR	= ar rcs

CFLAGS	= -Wall -Werror -Wextra

OBJ	= ${SRCS:.c=.o}

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx_macos -c $< -o $(<:.c=.o)

all: 	${NAME}

# Compile la lib

DIR_LIBFT = libft/

LIBFT_INC = -I $(DIR_LIBFT)

LIBFT = $(DIR_LIBFT)libft.a

FT_LINK = -L $(DIR_LIBFT) -l ft

# Compile la MiniLibX 

DIR_MLX = mlx_macos/

MLX_LNK = -L $(DIR_MLX) -lmlx -framework OpenGL -framework AppKit

MLX_INC = -I ${DIR_MLX}

MLX =   ${DIR_MLX}libmlx.a

LIBS = $(FT_LINK)    $(MLX_LNK)

$(LIBFT):
	$(MAKE) -sC $(@D)

$(MLX):
	$(MAKE) -sC $(@D)

$(NAME): ${LIBFT}	${MLX}	${OBJ}
	${CC}    ${OBJ} ${LIBS} -o ${NAME} 

clean:		
	${RM}	${OBJ}
	make fclean -C ./libft
	make clean -C ./mlx_macos

fclean:		clean
	${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
