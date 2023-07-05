SRC =	srcs/main.c \
			srcs/routine.c \
			srcs/error.c \
			srcs/time.c \
			srcs/utils.c \
			srcs/check.c \
			srcs/thread.c \

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread

NAME = philo

OBJ = $(SRC:.c=.o)

all: $(NAME)

.c .o:
		$(CC) -c $< -o $(<:.c=.o)

RM = rm -f

# Compile tout, sous le nom philo
${NAME}:	${OBJ}
			${CC}	${CFLAGS}	${OBJ} -o ${NAME}

clean:
		$(RM) $(OBJ) $(NAME)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all
