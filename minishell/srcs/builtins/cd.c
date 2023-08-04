/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:46:46 by robin             #+#    #+#             */
/*   Updated: 2023/08/03 18:04:30 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	export_pwd(const char *to_join)
{
	char	*joined_export_split_line;
	char	**splited_export_split_line;
	int		exit_code;

	joined_export_split_line
		= ft_strjoin(to_join, g_env.current_working_directory);
	if (joined_export_split_line == NULL)
		return (ERROR);
	splited_export_split_line = ft_split(joined_export_split_line, ' ');
	if (splited_export_split_line == NULL)
	{
		free(joined_export_split_line);
		return (ERROR);
	}
	exit_code = ft_export(splited_export_split_line);
	free(joined_export_split_line);
	split_free(splited_export_split_line);
	return (exit_code);
}

static int	change_directory_in_env(void)
{
	if ((get_env_var_index("OLDPWD=") != -1) 
		&& (export_pwd((char *)"export OLDPWD=")))
		return (ERROR);
	getcwd(g_env.current_working_directory, MAX_PATH_LEN + 1);
	if ((get_env_var_index((char *)"PWD=") != -1)
		&& (export_pwd((char *)"export PWD=")))
		return (ERROR);
	return (SUCCESS);
}

static int	change_dir(char *new_path)
{
	if (chdir(new_path) != 0)
	{
		perror("chdir");
		return (errno);
	}
	if (change_directory_in_env() == 1)
	{
		perror("chdirinenv");
		return (ERROR);
	}
	return (SUCCESS);
}

static int	go_home(void)
{
	char	*home;

	home = get_env_var_value((char *)"HOME");
	if (home == NULL)
		return (ERROR);
	change_dir(home);
	free(home);
	return (SUCCESS);
}

int	ft_cd(char **split_line)
{
	int		argc;
	char	*old_pwd;

	getcwd(g_env.current_working_directory, MAX_PATH_LEN);
	argc = 0;
	while (split_line[argc] != NULL)
		argc++;
	if (argc == 1)
		return (go_home());
	if (ft_strncmp(split_line[1], "-", 2) == 0)
	{
		if (argc > 2)
			return (ERROR);
		old_pwd = get_env_var_value("OLDPWD");
		if (old_pwd == NULL)
		{
			ft_putstr_fd("minishell: cd: OLDPWD not set\n", STDERR_FILENO);
			return (ERROR);
		}
		change_dir(old_pwd);
		free(old_pwd);
		return (SUCCESS);
	}
	return (change_dir(split_line[1]));
}
