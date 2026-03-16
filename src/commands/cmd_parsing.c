/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:10:52 by ncarrera          #+#    #+#             */
/*   Updated: 2026/03/16 14:02:23 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	handle_token(t_command **curr, char *token, t_input_info *info)
{
	if (ft_strncmp(token, "|", 2) == 0)
	{
		if (!(*curr)->args && !(*curr)->redirs)
		{
			info->shell->exit_code = 2;
			return (0);
		}
		(*curr)->next = new_command();
		*curr = (*curr)->next;
	}
	else if (is_operator(token[0]))
	{
		if (!redir_token(curr, token, info))
			return (0);
	}
	else
		add_argument(*curr, token, info->shell);
	return (1);
}

/*Loop*/
static int	parse_loop(t_command *head, char *line, t_mshell *shell)
{
	t_command		*curr;
	char			*token;
	int				i;
	t_input_info	info;

	curr = head;
	i = 0;
	info.line = line;
	info.i = &i;
	info.shell = shell;
	while (1)
	{
		token = get_next_token(&curr, &i);
		if (!token)
			break;
		if (!handle_token(&curr, token, &info))
		{
			free(token);
			return (0);
		}
		free(token);
	}
	return (1);
}

/*	Starts the list for each command && starts the loop to parse the input*/
char	*parse_input(char *line, t_mshell *shell)
{
	t_command	*head;
	t_command	*curr;

	head = new_command();
	if (!head)
		return (NULL);
	if (!parse_loop(head, line, shell))
	{
		free_commands(head);
		return (NULL);
	}
	if (head && !head->args && !head->redirs && !head->next)
		return (head);
	curr = head;
	while (curr->next)
		curr = curr->next;
	if (!curr->args && !curr->redirs)
	{
		shell->exit_code = 2;
		free_commands(head);
		return (NULL);
	}
	return (head);
}

/*	Allocates memory for, initializes and returns a cmd structure.
	Will return NULL on malloc failure.*/
t_command	*new_command(void)
{
	t_command *cmd;

	cmd = malloc(sizeof(t_command));
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->redirs = NULL;
	cmd->next = NULL;
	return (cmd);
}

/*	Handles case where first command is empty (i.e. "| ls").
	Shifts all following arguments forward by one if more than one
	command is present, and the first one is empty.*/
void	clean_empty_cmd(t_command *cmd)
{
	int	i;

	if (cmd->args && cmd->args[0] && !*cmd->args[0] && cmd->args[1])
	{
		i = 0;
		while (cmd->args[i + 1])
		{
			cmd->args[i] = cmd->args[i + 1];
			i++;
		}
		cmd->args[i] = NULL;
	}
}
