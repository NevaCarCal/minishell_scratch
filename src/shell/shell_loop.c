/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:21:23 by ncarrera          #+#    #+#             */
/*   Updated: 2026/03/16 13:51:33 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Creates local copy of the environment variables for manipulation.*/
static char	**dup_env(char **env)
{
	char	**new_env;
	int		i;

	i = 0;
	while (env[i])
		i++;
	new_env = (char **)malloc(sizeof(char *) * (i + 1));
	if (!new_env)
		return (NULL);
	i = 0;
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i;
	}
	new_env[i] = NULL;
	return (new_env);
}

/*	Frees all memory allocated for elements of env*/
void	free_env(char **env)
{
	int	i;

	if (!env)
		return ;
	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
}

/*	Takes the line passed to minishell, adds it to history, and
	parses and executes the commands in it as needed, handling
	memory allocation and freeing locally.*/
static void	process_line(char *line, t_mshell *shell)
{
	t_command	*cmds;

	if (*line)
	{
		add_history(line);
		cmds = parse_input(line, shell);
		if (cmds)
		{

		}
	}
}

/*	Checks and returns if user passes any arguments to minishell.
	Duplicates the current environment variables and adds them to shell struct.
	This allows minishell to manipulate, remove or add environment variables
	to its own list without altering the original one.*/
static int init_shell(t_mshell *shell, char **env, int argc)
{
	if (argc != 1)
	{
		printf("Error: no arguments allowed\n");
		return (1);
	}
	shell->exit_code = 0;
	shell->env = dup_env(env);
	if (!shell->env)
		return (1);
	return (0);
}

void	loop_shell(t_mshell *shell)
{
	char	*line;

	while (1)
	{
		line = readline("\001\033[1;35m\002minishell"
						"\001\033[1;36m\002$ \001\033[0m\002");
		if (!line)
		{
			printf("exit\n");
			break;
		}
		process_line(line, shell);
		if (g_signal != 0)
		{
			shell->exit_code = g_signal;
			g_signal = 0;
		}
	}
}
