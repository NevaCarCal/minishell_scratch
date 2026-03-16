/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 10:09:31 by ncarrera          #+#    #+#             */
/*   Updated: 2026/03/16 11:56:42 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_operator(char c)
{
	return (c == '|' || c == '<' || c == '>');
}

static int	get_word_len(char *line)
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

/*	This current code and what uses it is prone to failure since there
	are no checks on whether the passed input is valid (For example,
	the oprators could be something like >< which if passed
	could cause issues.)*/
static int	get_operator_len(char *line)
{
	if (!line || !*line)
		return (0);
	if (line[0] == '>' && line[1] == '>')
		return (2);
	if (line[0] == '<' && line[1] == '<')
		return (2);
	return (1);
}

/*	Extracts the next token (Operator, word, char, etc.) from the line
	starting at idx. It skips leading whitespaces and allocates memory for
	the returned token. Idx is updated after the token is extracted.
	Returns NULL on malloc failure or the end of the line is reached.*/
char	*get_next_token(char *line, int *idx)
{
	int		start;
	int		len;
	char	*token;

	while (line[*idx] && ft_isspace(line[*idx]))
		(*idx)++;
	if (!line[*idx])
		return (NULL);
	start = *idx;
	if (is_operator(line[*idx]))
		len = get_operator_len(line + *idx);
	else
		len = get_word_len(line + *idx);
	token = malloc(sizeof(char) * (len + 1));
	if (!token)
		return (NULL);
	ft_strlcpy(token, line + start, len + 1);
	*idx += len;
	return (token);
}
/* tokenizer ?¿ dos opciones palabras o operadores, needed aqui? o asignar
en la lista de cmd, si es operador o comand olo que sea? posible replanteazion
de eso para facilitar lo que aun no esta corregido? */
