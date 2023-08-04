/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:11:17 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/08/04 14:51:17 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define MAX_ENV 1000
# define MAX_PATH_LEN 4096

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <errno.h>
# include "../libft/libft.h"

typedef enum e_bool {
	FALSE,
	TRUE,
	SUCCESS = 0,
	ERROR = 1,
}	t_bool;

typedef struct s_env
{
	char					**env;
	char					current_working_directory[MAX_PATH_LEN];
	char					*prompt_msg;
	volatile sig_atomic_t	g_minishell_status;
}			t_env;

typedef struct s_fd
{
	int	in;
	int	out;
}	t_fd;

typedef enum e_minishell_status {
	S_EXEC,
	S_EXEC_ABORT,
	S_PROMPT,
	S_HEREDOC,
	S_HEREDOC_ABORT,
}	t_minishell_status;

typedef enum e_node_type
{
	AST_ROOT,
	AST_BUILTIN,
	AST_CMD,
	AST_NOTHING,
	AST_REDIR_IN,
	AST_REDIR_OUT,
	AST_HEREDOC,
	AST_APP,
	AST_PIPE,
	AST_INVALID,
	AST_SIZE,
}	t_node_type;

typedef struct s_tmp
{
	int	pipe_count;
	int	*p;
	int	*all_pipes;
	int	*all_redir;
	int	*redir_pos;
}	t_tmp;

typedef struct s_node
{
	t_node_type		type;
	void			*content;
	int				fd_in;
	int				fd_out;
	int				redir_fd_in;
	int				redir_fd_out;
	int				pipe_count;
	int				*pipe_index;
	int				*all_pipe;
	int				*all_redir;
	int				*redir_pos;
	int				exit_status;
	pid_t			pid;
	struct s_node	*children[2];
}	t_node;

typedef struct s_cmd
{
	char	*cmd_name;
	char	**args;
}			t_cmd;

typedef enum e_token_type
{
	T_WORD = 0,
	T_S_QUOTE,
	T_D_QUOTE,
	T_VAR,
	T_PIPE,
	T_WILDCARD,
	T_REDIR_IN,
	T_REDIR_OUT,
	T_REDIR_APP,
	T_HEREDOC,
	T_SPACE,
	T_BRACKET_OPN,
	T_BRACKET_CLSE,
	T_INVALID,
}	t_token_type;

typedef struct s_token
{
	t_token_type	type;
	char			*content;
	int				rmv;
}	t_token;

typedef struct t_tokenizer
{
	t_list	*tokens;
	char	*input;
	int		status;
	int		index;
}	t_tokenizer;

typedef struct s_builtin
{
	int		(*func_pointer)(char **);
	char	**args;
}			t_builtin;

extern t_env	g_env;

// main.c
int			main(int ac, char **av, char **env);
int			env_setup(char **env);
int			ft_init_read(char **line);
int			tokens_parse(t_token ***tokens, char *line);
// increase_shlvl.c
void		increase_shlvl(void);
// ft_print_message.c
void		print_welcome_msg(void);
// ft_free.c
int			free_args(char **str);
void		destroy_token(t_token *token);
void		tokens_destroy(t_token **tokens);
void		tokenizer_destroy(t_tokenizer *tok);
// ft_put_error.c
void		ft_put_error(char *cause, const char *err_msg);
//signal.c
int			signal_setup(void);
void		handle_sigint(void);
void		handle_sigquit(void);
void		signal_handler(int sig);
// echo.c
int			ft_echo(char **split_line);
int			ft_env(char **split_line);
int			ft_export(char **split_line);
int			ft_pwd(char **line);
int			ft_unset(char **split_line);
// tokenize.c
t_tokenizer	*toker_init(char *input, int status);
t_token		**token_parse(t_tokenizer *tok);
t_token		**tokenizer_input(char *input, int status);
t_token		*ft_token_next_token(t_tokenizer *tok);
// token_parse.c
t_token		**token_parse(t_tokenizer *tok);
// space_sq.c
void		ft_space(t_tokenizer *tok, t_token *token);
void		simple_quote(t_tokenizer *tok, t_token *token);
// d_q.c
void		double_quote(t_tokenizer *tok, t_token *token);
// generate_token.c
void		generate_token(t_token *token, char *src, int size);
// tok_handle.c
void		token_tilde(t_tokenizer *tok, t_token *token);
void		token_redir_o(t_tokenizer *tok, t_token *token);
void		token_redir_i(t_tokenizer *tok, t_token *token);
void		token_pipe(t_tokenizer *tok, t_token *token);
void		token_bracket(t_tokenizer *tok, t_token *token);
// env_index_value.c
char		*get_env_var_value(char *var_name);
int			get_env_var_index(char *var);
int			add_env_var(char *var);
int			get_env_var_index_nonequal(char *var);
// token_word.c
void		token_word(t_tokenizer *tok, t_token *token);
// token_var.c
void		token_var(t_tokenizer *tok, t_token *token);
int			token_var_len(t_tokenizer *tok);
// tokenize_in_array;
t_token		**token_in_array(t_tokenizer *tok);
// ft_check_syntax.c
int			ft_check_syntax(t_token **token);
int			is_redir(t_token *token);
// check_word_around.c
int			check_word_around(t_token **token, int pos);
// check_bracket.c
int			check_bracket_num(t_token **token);
int			check_bracket_o(t_token **token);
int			check_bracket_c(t_token **token);
// token_utils.c
int			token_size(t_token **token);
void		remove_spaces(t_token **agreg, t_token **token, int *i, int *j);
void		remove_useless(t_token **token);
t_token		**agregate_spaces(t_token **token, int size);
// tokenutils.c
void		to_word(t_token **token);
int			token_size(t_token **token);
// agregate_redir
void		agregate_redir(t_token ***token);
// expand_one.c
t_token		**expand_one(t_token **token, int size);
// ast_init.c
int			ast_init(t_node **root, t_token **token);
t_node		*ast_generate(t_token **token);
// setup_pipe.c
void		setup_pipe(t_node *root, t_token **token, t_tmp *tmp);
// setup_redir.c
void		setup_redir(t_node *root, t_token **token, t_tmp *tmp);
// node_gen_redir.c
int			node_gen_redir(t_node *root, t_token **token, int start, int size);
// ast_utils.c
void		node_destroy(t_node *root);
t_node		*ast_node_create(t_token **token, int start, int size, t_tmp tmp);
int			max(int a, int b);
int			here_doc(int pipe_fd[2], t_token *token);
void		restore_fds(t_node *root, int fd_out, int fd_in);
// redir_create.c
t_fd		create_heredoc(t_token *token);
int			redir_create(t_token *token);
// ast_find_type.c
int			find_type(t_node *root, t_token **token, int start, int size);
// node_gen_redir.c
int			node_gen_redir(t_node *root, t_token **token, int start, int size);
// node_generate_content.c
void		nd_generate_content(t_node *root, t_token **token,
				int start, int size);
int			ast_find_name_pos(t_token **token, int start, int size);
char		**ast_gen_args(t_token **token, int size, int start);
// ast_root_gen_built.c
void		ast_root_gen_built(t_node *root,
				t_token **token, int size, int start);
// ast_execute.c
void		ast_execute(t_node *root);
int			ast_node_redirect(t_node *root);
void		ast_close_redir(t_node *root);
void		ast_close_pipe(t_node *root);
// handle_pipe.c
void		handle_pipe(t_node *root);
// ast_execute_cmd.c
void		ast_execute_cmd(t_node *root);
// get_env.c
char		*ms_getenv_cont(char *name);
char		*ms_getenv(char	*name);
// ast_wait.c
int			ast_wait(t_node *root);
// root_destroy.c
void		root_destroy(t_node *root);

int			signal_setup(void);
void		handle_sigint(void);
void		handle_sigquit(void);
void		signal_handler(int sig);
// tokenizer.c
// t_token	**tokenizer(char *input, int status);

//builtins.c
int			ft_pwd(char **split_line);
int			ft_echo(char **split_line);
int			ft_env(char **split_line);
int			ft_export(char **argv);
int			ft_unset(char **split_line);
int			ft_cd(char **split_line);
int			ft_exit(char **argv);

//env_index_value.c
char		*get_env_var_value(char *var_name);
int			get_env_var_index(char *var);
int			get_env_var_index_nonequal(char *var);

//add_env_var.c
int			add_env_var(char *var);

//utils
void		split_free(char **list);

#endif