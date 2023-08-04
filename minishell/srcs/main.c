/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:08:05 by rgodtsch          #+#    #+#             */
/*   Updated: 2023/08/04 15:55:28 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>

t_env	g_env;

// parsing et retour d'erreur
int	tokens_parse(t_token ***tokens, char *line)
{
	*tokens = tokenizer_input(line, g_env.g_minishell_status);
	g_env.g_minishell_status = ft_check_syntax(*tokens) - 1;
	if (g_env.g_minishell_status + 1)
	{
		tokens_destroy(*tokens);
		return (0);
	}
	return (1);
}

// initialise le prompt
int	ft_init_read(char **line)
{
	g_env.g_minishell_status = 1;
	*line = readline("[Minishell] : ");
	if (*line == NULL || ft_strncmp(*line, "exit", 5) == 0)
		ft_exit(NULL);
	if (ft_strlen(*line) == 0)
	{
		free(*line);
		return (0);
	}
	add_history(*line);
	return (1);
}

// setup l'env dans la struct globale
int	env_setup(char **env)
{
	int	i;

	g_env.env = ft_calloc((MAX_ENV + 2), sizeof(char *));
	if (!g_env.env)
		return (0);
	i = -1;
	while (++i < MAX_ENV && env[i])
	{
		g_env.env[i] = ft_strdup(env[i]);
		if (!g_env.env[i])
		{
			free_args(g_env.env);
			return (0);
		}
	}
	if (env[i])
	{
		free_args(g_env.env);
		return (0);
	}
	g_env.g_minishell_status = 0;
	print_welcome_msg();
	increase_shlvl();
	return (1);
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	t_token	**token;
	t_node	*root;

	(void)av;
	if (ac != 1)
		return (printf("No arguments needed\n"), 0);
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	if (!env_setup(env))
		return (-1);
	while (1)
	{
		if (!ft_init_read(&line)
			|| !tokens_parse(&token, line) || !ast_init(&root, token))
			continue ;
		ast_execute(root);
		ast_close_pipe(root);
		ast_close_redir(root);
		g_env.g_minishell_status = ast_wait(root);
		root_destroy(root);
	}
	return (0);
}
