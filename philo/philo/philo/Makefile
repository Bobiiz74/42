# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ktomat <ktomat@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/22 14:55:53 by vgroux            #+#    #+#              #
#    Updated: 2023/06/14 10:50:25 by ktomat           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREENGREEN = \033[38;5;46m
RED = \033[0;31m
GREY = \033[38;5;240m
RESET = \033[0m

NAME =     philo

CC =         gcc
CFLAGS =     -Wall -Wextra -Werror
RM =         rm -rf

SFLAGS = -fsanitize=thread 

DIR_H = header/
DIR_S =	src/
DIR_O =	objs/
DIR_SAN = san/

SRCS_LIST =	main.c \
			error.c \
			utils.c \
			time.c \
			thread_start.c \
			routine.c \
			checker.c \
			
			
			
			

SRCS =		${addprefix ${DIR_S}, ${SRCS_LIST}}

OBJS =		${SRCS:${DIR_S}%.c=${DIR_O}%.o}

SAN-OBJS =	${SRCS:${DIR_S}%.c=${DIR_SAN}%.o}

${NAME}: ${OBJS}
	@echo "$(RESET)[$(GREENGREEN)${NAME}$(RESET)]: ${NAME} objects were created${GREY}"
	${CC} ${OBJS} -lpthread -o ${NAME}
	@echo "$(RESET)[$(GREENGREEN)${NAME}$(RESET)]: ${NAME} created !"

all: ${NAME}

san: fclean ${SAN-OBJS}
	${CC} ${SAN-OBJS} -lpthread -o ${NAME} ${SFLAGS}

${DIR_O}%.o:${DIR_S}%.c
	@printf "${GREY}"
	@mkdir -p ${DIR_O}
	${CC} ${CFLAGS} -I ${DIR_H} -o $@ -c $<

${DIR_SAN}%.o:${DIR_S}%.c
	@printf "${GREY}"
	@mkdir -p ${DIR_SAN}
	${CC} ${CFLAGS} ${SFLAGS} -I ${DIR_H} -o $@ -c $<

clean:
	@echo "[$(RED)${NAME}$(RESET)]: cleaning ${NAME} objects...${GREY}"
	${RM} ${OBJS}
	${RM} ${DIR_O}
	${RM} ${DIR_SAN}
	@echo "[$(RED)${NAME}$(RESET)]: ${NAME} objects were cleaned${GREY}"

fclean: clean
	@echo "${RESET}[$(RED)${NAME}$(RESET)]: cleaning ${NAME}...${GREY}"
	${RM} ${NAME}
	@echo "${RESET}[$(RED)${NAME}$(RESET)]: ${NAME} executable was cleaned"

printcompil:
	@echo "$(RESET)[$(GREENGREEN)${NAME}$(RESET)]: ${NAME} objects compilation...${GREY}"

re: fclean printcompil all

.PHONY: all clean fclean re