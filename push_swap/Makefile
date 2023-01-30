SRCS	= main.c

NAME	= push_swap

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Werror -Wextra

OBJS	= ${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} 
	make -C ./libft
	mv ./libft/libft.a 	./
	${CC} -o ${NAME} ${OBJS} -L. -lft

all: 	${NAME}

clean:		
	make fclean -C ./libft
	${RM} ${OBJS}

fclean:		clean
	rm -f ./libft/libft.a
	${RM} ${OBJS} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
