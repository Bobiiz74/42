/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_wait.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:08:18 by ppotier           #+#    #+#             */
/*   Updated: 2023/07/28 15:24:16 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	convert_stat_loc(int stat_loc)
{
	int	status;

	status = 231;
	if (WIFEXITED(stat_loc))
		status = WEXITSTATUS(stat_loc);
	else if (WIFSIGNALED(stat_loc))
		status = WTERMSIG(stat_loc) + 128;
	return (status);
}

int	ast_wait(t_node *root)
{
	int	status;
	int	stat_loc;

	status = 69;
	if (!root)
		return (0);
	if (root->type == AST_ROOT)
	{
		status = ast_wait(root->children[0]);
		return (status);
	}
	if (root->pid != -1 && (root->type == AST_CMD || root->type == AST_BUILTIN))
	{
		waitpid(root->pid, &stat_loc, 0);
		status = convert_stat_loc(stat_loc);
	}
	else if (root->exit_status != -1)
		status = root->exit_status;
	ast_wait(root->children[0]);
	if (root->children[1])
		status = ast_wait(root->children[1]);
	return (status);
}
