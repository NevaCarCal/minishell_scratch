/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:37:04 by ncarrera          #+#    #+#             */
/*   Updated: 2026/03/16 10:37:20 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_word_len(char *line)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (line[i])
	{
		ft_update_quote(line[i], &quote); /*revisar si queremos hacerlo asi */
		if (!quote && is_operator(line[i]))
			break;
		if (!quote && ft_isspace(line[i]))
			break;
		i++;
	}
	return (i);
}

int	get_operator_len(char *line)
{
	if (!line || !*line)
		return (0);
	if (line[0] == '>' && line[1] == '>')
		return (2);
	if (line[0] == '<' && line[1] == '<')
		return (2);
	return (1);
}
