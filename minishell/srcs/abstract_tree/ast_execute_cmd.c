/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_execute_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:00:47 by ppotier           #+#    #+#             */
/*   Updated: 2023/07/28 15:24:39 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_full_command(char *directory, char *cmd_name)
{
	char	*tmp;
	char	*command;

	tmp = ft_strjoin(directory, "/");
	if (!tmp)
		return (NULL);
	command = ft_strjoin(tmp, cmd_name);
	free (tmp);
	return (command);
}

int	check_relative(char *cmd)
{
	if (ft_strncmp(cmd, "./", 2) == 0)
		return (1);
	else if (ft_strncmp(cmd, "../", 3) == 0)
		return (1);
	else if (cmd[0] == '/')
		return (1);
	return (0);
}

int	check_access_status(char *path, char *cmd_name)
{
	struct stat	file_stat;

	if (!path || !ft_strncmp(cmd_name, "..", 3) || !ft_strncmp(cmd_name, ".", 2)
		|| ft_strlen(cmd_name) == 0)
	{
		ft_put_error(cmd_name, "command not found");
		return (127);
	}
	stat(path, &file_stat);
	if (S_ISDIR(file_stat.st_mode))
	{
		ft_put_error(cmd_name, "is a directory");
		return (126);
	}
	if (access(path, F_OK) != 0)
	{
		ft_put_error(cmd_name, "No suchlkwqael file or directory");
		return (127);
	}
	if (access(path, X_OK) != 0)
	{
		ft_put_error(cmd_name, "Permission denied");
		return (126);
	}
	return (0);
}

char	*get_cmd(char *cmd)
{
	char	*command;
	char	*env_path;
	char	**path;
	int		i;

	command = NULL;
	if (check_relative(cmd))
		return (ft_strdup(cmd));
	env_path = ms_getenv_cont("PATH");
	if (!env_path)
		return (NULL);
	path = ft_split(env_path, ':');
	free(env_path);
	i = -1;
	while (path[++i])
	{
		command = get_full_command(path[i], cmd);
		if (access(command, F_OK) == 0)
			break ;
		free(command);
		command = NULL;
	}
	free_args(path);
	return (command);
}

void	ast_execute_cmd(t_node *root)
{
	t_cmd	*cmd;
	char	*full_path;
	int		status;

	cmd = (t_cmd *) root->content;
	full_path = get_cmd(cmd->cmd_name);
	status = check_access_status(full_path, cmd->cmd_name);
	if (status)
	{
		root->exit_status = status;
		free(full_path);
		return ;
	}
	root->pid = fork();
	if (root->pid == 0)
	{
		ast_node_redirect(root);
		execve(full_path, cmd->args, g_env.env);
	}
	free (full_path);
}
