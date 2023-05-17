SRC =	srcs/main.c \
		srcs/init_thread.c \
		srcs/init_struct.c \
	
CC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread

NAME = philo

OBJ = $(SRC:.c=.o)

all: $(NAME)

.c .o:
		$(CC) -c $< -o $(<:.c=.o)

RM = rm -f

# Compile la lib
DIR_LIBFT = libft/
LIBFT_INC = -I $(DIR_LIBFT)
LIBFT = $(DIR_LIBFT)libft.a
FT_LINK = -L $(DIR_LIBFT) -l ft

LIBS = $(FT_LINK)

# Make la lib
$(LIBFT):
		$(MAKE) -sC $(@D)

# Compile tout, sous le nom philo
${NAME}:	${LIBFT}	${OBJ}
			${CC}	${OBJ}	$(LIBS) -o ${NAME}

clean:
		$(RM) $(OBJ) $(NAME)

fclean:	clean
		make fclean -C ./libft
		$(RM) $(NAME)

re:		fclean all
