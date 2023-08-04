# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: robin <robin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 14:50:47 by ppotier           #+#    #+#              #
#    Updated: 2023/07/07 14:41:2 by robin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = srcs

SRC_FILES = main.c \
			signal.c \
			ft_print_mssg.c \
			ft_free.c \
			ft_put_error.c \
			utils.c \
			builtins/echo.c \
			builtins/pwd.c \
			builtins/env.c \
			builtins/export.c \
			builtins/unset.c \
			builtins/cd.c \
			builtins/exit.c \
			add_env_var.c \
			env_index_value.c \
			increase_shlvl.c \
			token/space_sq.c \
        	token/d_q.c \
        	token/generate_token.c \
        	token/tok_handle.c \
        	token/token_word.c \
			token/token_var.c \
			token/token_in_array.c \
        	token/tokenize.c \
			token/check_bracket.c \
			token/check_word_around.c \
			token/ft_check_syntax.c \
			token/token_utils.c \
			token/tokenutils.c \
			token/agregate_redir.c \
			abstract_tree/setup_pipe.c \
			abstract_tree/setup_redir.c \
			abstract_tree/ast_find_type.c \
			abstract_tree/ast_utils.c \
			abstract_tree/redir_create.c \
			abstract_tree/node_generate_content.c \
			abstract_tree/ast_init.c \
			abstract_tree/ast_root_gen_built.c \
			abstract_tree/node_gen_redir.c \
			abstract_tree/ast_execute.c \
			abstract_tree/handle_pipe.c \
			abstract_tree/ast_execute_cmd.c \
			abstract_tree/get_env.c \
			abstract_tree/ast_wait.c \
			abstract_tree/root_destroy.c \

SRC = $(addprefix $(SRC_DIR)/,$(SRC_FILES))

CC = gcc

export LDFLAGS="-L$(HOME)/.brew/opt/readline/lib"
export CPPFLAGS="-I$(HOME)/.brew/opt/readline/include"

CFLAGS = -Wall -Wextra -Werror $(CPPFLAGS) -fsanitize=address -static-libsan

NAME = minishell

OBJ_DIR = objs
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR)/,$(OBJ_FILES))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

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

# Compile tout
$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -lreadline $(LIBS) -o $(NAME)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	make fclean -C $(DIR_LIBFT)
	$(RM) $(NAME)

re: fclean all
