/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:21:23 by ncarrera          #+#    #+#             */
/*   Updated: 2026/03/16 10:22:18 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
