SRCS	= ft_printf.c \
		  ft_add.c \
		  ft_print_hex.c \
		  ft_print_p.c

NAME	= libftprintf.a

CC	= gcc

RM	= rm -f

AR	= ar rcs

CFLAGS	= -Wall -Werror -Wextra

OBJS	= ${SRCS:.c=.o}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS} 
	make bonus -C ./libft
	mv ./libft/libft.a 	${NAME}
	${AR} ${NAME} ${OBJS} 

all: 	${NAME}

clean:		
	make fclean -C ./libft
	${RM} ${OBJS}

fclean:		clean
	${RM} ${NAME}

re:		fclean all

.PHONY:		all clean fclean re
