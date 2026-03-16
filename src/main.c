/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 13:46:39 by ncarrera          #+#    #+#             */
/*   Updated: 2026/03/14 13:46:39 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int g_signal = 0;

/*Handles sigint as specified in subject*/
static void handle_sigint(int sig)
{
	g_signal = 128 + sig;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

/*Handles the values for the signals delivereds by the keyboard (EX: SIGINT "signal interruption" = ctr + c), (ex: SIGQUIT "signal quit" = ctr + /)*/
static void	setup_signals(void)
{
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}

int	main(int argc, char **argv, char **env)
{
	t_mshell	shell;

	(void)argv;
	if (init_shell(&shell, env, argc))
		return (1);
	setup_signals();
	loop_shell(&shell);
	rl_clear_history();
	free_env(shell.env);
	return (shell.exit_code);
}
