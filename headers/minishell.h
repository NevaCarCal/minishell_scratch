/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 13:42:49 by ncarrera          #+#    #+#             */
/*   Updated: 2026/03/16 11:33:50 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
#endif

/*Libraries*/

extern int	g_signal;

/*Environment*/
typedef struct	s_mshell
{
	char	**env;
	int		exit_code;
}	t_mshell;

/*Input*/
typedef struct	s_input_info
{
	char		*line;
	int			*i;
	t_mshell	*shell;
}	t_input_info;

/*Commands*/
/*Define type of command*/
typedef enum	e_redir_type
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_HEREDOC,
}	t_redir_type;

typedef struct	s_redir
{
	t_redir_type	type;
	char			*file;
	struct s_redir	*next;
}	t_redir;

typedef struct	s_command
{
	char				**args;
	t_redir				*redirs;
	struct s_command	*next;
}	t_command;

/*Shell*/
void	loop_shell(t_mshell *shell);

/*Line tools*/
int		is_operator(char c);
char	*get_next_token(char *line, int *idx);
