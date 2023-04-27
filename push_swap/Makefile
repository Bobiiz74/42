# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 14:50:47 by ppotier           #+#    #+#              #
#    Updated: 2023/04/20 16:55:21 by ppotier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	srcs/cost.c \
		srcs/error.c \
		srcs/main.c \
		srcs/move.c \
		srcs/quick_sort.c \
		srcs/rev_rotate.c \
		srcs/rotate.c \
		srcs/sort.c	\
		srcs/swap.c \
		srcs/utils.c \
		srcs/push.c \
		srcs/ft_check_input.c \
		
CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

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

# Compile tout, sous le nom fdf
${NAME}:	${LIBFT}	${OBJ}
			${CC}	${OBJ}	$(LIBS) -o ${NAME}

clean:	
		$(RM) $(OBJ) $(NAME)

fclean:	clean
		make fclean -C ./libft
		$(RM) $(NAME)

re:		fclean all
