/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppotier <ppotier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:47:07 by robin             #+#    #+#             */
/*   Updated: 2023/08/04 16:07:47 by ppotier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "minishell.h"
#include <termios.h>

// utilisée pour configurer les attributs du terminal en modifiant 
// la structure `termios` 
// pour désactiver l'affichage des caractères de contrôle et en utilisant `
// tcsetattr` pour appliquer ces changements au terminal
void	init_termios(void)
{
	struct termios		termios;
	struct sigaction	sig;

	sig.sa_handler = &signal_handler;
	if ((tcgetattr(STDIN_FILENO, &termios)) == -1)
		exit(EXIT_FAILURE);
	termios.c_lflag &= ~(ECHOCTL);
	if ((tcsetattr(STDIN_FILENO, TCSANOW, &termios)) == -1)
		exit(EXIT_FAILURE);
}

void	handle_sigint(void)
{
	init_termios();
	if (g_env.g_minishell_status == 1)
	{
		rl_replace_line("", 0);
		printf("\n");
		rl_on_new_line();
		rl_redisplay();
	}
	if (g_env.g_minishell_status == 0)
	{
		printf("\n");
		g_env.g_minishell_status = 1;
	}
}

void	handle_sigquit(void)
{
	rl_on_new_line();
	rl_redisplay();
}

void	signal_handler(int sig)
{
	if (sig == SIGINT)
		handle_sigint();
	if (sig == SIGQUIT)
		handle_sigquit();
}
