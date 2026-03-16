/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:10:52 by ncarrera          #+#    #+#             */
/*   Updated: 2026/03/16 11:34:06 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* tokenizer ?¿ dos opciones palabras o operadores, needed aqui? o asignar
en la lista de cmd, si es operador o comand olo que sea? posible replanteazion
de eso para facilitar lo que aun no esta corregido? */

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

/*Loop */
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

/*Starts the list for each command && starts the loop to parse the input*/
static char	*parse_input(char *line, t_mshell *shell)
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

/*  add_history saves log from inputs
	initialize the parsing of the input
	initialize the execute of "commands" that have been parsed*/
static void	process_line(char *line, t_mshell *shell)
{
	t_command	*cmds;

	if (*line)
	{
		add_history(line);
		cmds = parse_input(line, shell);
		if (cmds)
		{
			execute_command(shell, cmds);
			free_commands(cmds);
		}
	}
	free(line);
}
