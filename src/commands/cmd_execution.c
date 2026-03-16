/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_execution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:30:09 by ncarrera          #+#    #+#             */
/*   Updated: 2026/03/16 14:50:55 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int is_builtin(char *cmd) { (void)cmd; return 0; }
void exec_single_builtin(t_command *cmd, t_mshell *shell) { (void)cmd; (void)shell; }
// Stubs to avoid compile errors
void exec_child(t_command *cmd, t_mshell *shell, int prev_fd, int *pip) { (void)cmd; (void)shell; (void)prev_fd; (void)pip; exit(0); }
void handle_parent(int *prev_fd, int *pip) { (void)prev_fd; (void)pip; }

/*	Waits for last command in the pipeline to finish and saves exit code.
	Waits for all earlier commands in the pipeline to finish.*/
static void	wait_all(pid_t last_pid, t_mshell *shell)
{
	int	status;

	if (last_pid != -1)
	{
		waitpid(last_pid, &status, 0);
		if (WIFEXITED(status))
			shell->exit_code = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			shell->exit_code = 128 + WTERMSIG(status);
	}
	while (wait(NULL) > 0)
		;
}

static int	*get_next_pipe(t_command *cmd, int *pip)
{
	if (cmd->next)
		return (pip);
	return (NULL);
}

void	execute_command(t_mshell *shell, t_command *cmd)
{
	int		prev_fd;
	int		pip[2];
	pid_t	pid;

	prev_fd = -1;
	pid = -1;
	while (cmd)
	{
		clean_empty_cmd(cmd);
		if (cmd->next && pipe(pip) == -1)
			return (perror("pipe"));
		if (cmd->args && cmd->args[0] && is_builtin(cmd->args[0])
			&& !cmd->next && prev_fd == -1)
			exec_single_builtin(cmd, shell);
		else
		{
			pid = fork();
			if (pid == 0)
				exec_child(cmd, shell, prev_fd, get_next_pipe(cmd, pip));
		}
		handle_parent(&prev_fd, get_next_pipe(cmd, pip));
		cmd = cmd->next;
	}
	wait_all(pid, shell);
}
