/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:25:02 by ncarrera          #+#    #+#             */
/*   Updated: 2026/03/16 14:31:58 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Check if *var exists within **env. Returns the index of var if found.
	If *var is not found, returns -1.*/
int	env_var_exists(char *var, char **env)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (var[len] && var[len] != '=')
		len++;
	while (env[i])
	{
		if (ft_strncmp(env[i], var, len) == 0 && (
				env[i][len] == '=' || env[i][len] == '\0'))
			return (i);
		i++;
	}
	return (-1);
}

/* Creates a new env list without the var at index by allocating new memory */
static char	**remove_env_var(char **env, int index)
{
	int		i;
	int		j;
	char	**new_env;

	i = 0;
	while (env[i])
		i++;
	new_env = malloc(sizeof(char *) * i);
	if (!new_env)
		return (env);
	i = -1;
	j = 0;
	while (env[++i])
	{
		if (i != index)
			new_env[j++] = env[i];
		else
			free(env[i]);
	}
	new_env[j] = NULL;
	free(env);
	return (new_env);
}

/*	Removes select env variable from the env list.*/
void	builtin_unset(t_mshell *shell, char **args)
{
	int	i;
	int	idx;

	i = 1;
	while (args[i])
	{
		idx = env_var_exists(args[i], shell->env);
		if (idx >= 0)
			shell->env = remove_env_var(shell->env, idx);
		i++;
	}
	shell->exit_code = 0;
}

/* Prints entire env list out to stdout */
void	builtin_env(t_mshell *shell)
{
	int	i;

	i = 0;
	while (shell->env[i])
	{
		if (ft_strchr(shell->env[i], '='))
		{
			ft_putstr_fd(shell->env[i], 1);
			ft_putchar_fd('\n', 1);
		}
		i++;
	}
	shell->exit_code = 0;
}
