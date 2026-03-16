/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:03:23 by ncarrera          #+#    #+#             */
/*   Updated: 2026/03/16 14:23:43 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	read_heredoc_loop(int fd, char *delimiter)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter) + 1) == 0)
		{
			free(line);
			break ;
		}
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
		free(line);
	}
}

static int	handle_heredoc(char *delimiter)
{
	int		fd;

	fd = open(".heredoc_tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (-1);
	read_heredoc_loop(fd, delimiter);
	close(fd);
	fd = open(".heredoc_tmp", O_RDONLY);
	unlink(".heredoc_tmp");
	return (fd);
}

/*	Opens a file based on the type of redirection.
	Returns the file descriptor or -1 on failure.*/
static int	open_file(char *file, int type)
{
	int	fd;

	if (type == REDIR_IN)
		fd = open(file, O_RDONLY);
	else if (type == REDIR_OUT)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (type == REDIR_APPEND)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (type == REDIR_HEREDOC)
		fd = handle_heredoc(file);
	else
		return (-1);
	if (fd == -1)
	{
		perror(file);
		return (-1);
	}
	return (fd);
}

/*	Handles all redirections for a command. Calls open_file for each fd.
	Returns 1 on success, 0 on failure.*/
static int	handle_redirections(t_redir *redirs)
{
	int	fd;

	while (redirs)
	{
		fd = open_file(redirs->file, redirs->type);
		if (fd == -1)
			return (0);
		if (redirs->type == REDIR_IN || redirs->type == REDIR_HEREDOC)
			dup2(fd, STDIN_FILENO);
		else
			dup2(fd, STDOUT_FILENO);
		close(fd);
		redirs = redirs->next;
	}
	return (1);
}

static void	exec_builtin(t_mshell *shell, char **args)
{
	if (ft_strncmp(args[0], "cd", 3) == 0)
		builtin_cd(shell, args);
	else if (ft_strncmp(args[0], "pwd", 4) == 0)
		builtin_pwd(shell);
	else if (ft_strncmp(args[0], "env", 4) == 0)
		builtin_env(shell);
	else if (ft_strncmp(args[0], "exit", 5) == 0)
		builtin_exit(shell, args);
	else if (ft_strncmp(args[0], "echo", 5) == 0)
		builtin_echo(shell, args);
	else if (ft_strncmp(args[0], "export", 7) == 0)
		builtin_export(shell, args);
	else if (ft_strncmp(args[0], "unset", 6) == 0)
		builtin_unset(shell, args);
}

/*	Executes builtins in cases where only one needs to be executed.*/
void	exec_single_builtin(t_command *cmd, t_mshell *shell)
{
	int	saved_std[2];

	saved_std[0] = dup(STDIN_FILENO);
	saved_std[1] = dup(STDOUT_FILENO);
	if (handle_redirections(cmd->redirs))
		exec_builtin(shell, cmd->args);
	else
		shell->exit_code = 1;
	dup2(saved_std[0], STDIN_FILENO);
	dup2(saved_std[1], STDOUT_FILENO);
	close(saved_std[0]);
	close(saved_std[1]);
}
