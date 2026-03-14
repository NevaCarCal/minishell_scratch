/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:44:33 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/06 14:53:00 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_eol_eof(char c)
{
	if (c == '\n' || c == '\0')
		return (1);
	return (0);
}

static char	*read_until_nl(int fd, char *persistent_buff, char *buff)
{
	ssize_t	ctr;
	char	*t_buff;

	ctr = 1;
	while (ctr > 0)
	{
		ctr = read(fd, buff, BUFFER_SIZE);
		if (ctr < 0)
		{
			free(persistent_buff);
			return (NULL);
		}
		if (ctr == 0)
			break ;
		buff[ctr] = '\0';
		if (!persistent_buff)
			persistent_buff = ft_gstrdup("");
		t_buff = persistent_buff;
		persistent_buff = ft_gstrjoin(t_buff, buff);
		free(t_buff);
		t_buff = NULL;
		if (ft_gstrchr(buff, '\n'))
			break ;
	}
	return (persistent_buff);
}

static char	*split_after_nl(char *line)
{
	size_t	ctr;
	char	*buff;

	ctr = 0;
	if (!line)
		return (NULL);
	while (!ft_is_eol_eof(line[ctr]))
		ctr++;
	if (line[ctr] == '\0' || line[ctr + 1] == '\0')
		return (NULL);
	buff = ft_gsubstr(line, ctr + 1, ft_gstrlen(line) - ctr);
	if (buff == NULL)
		return (NULL);
	line[ctr + 1] = '\0';
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*p_buff;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(p_buff);
		free(buffer);
		p_buff = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = read_until_nl(fd, p_buff, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	p_buff = split_after_nl(line);
	return (line);
}
