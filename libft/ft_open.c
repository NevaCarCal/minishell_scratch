/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:51:08 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/11 02:23:22 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_open(char *filename, int flag)
{
	int	fd;

	fd = open(filename, flag);
	if (fd == -1)
		ft_printf("\x1b[1;31mError opening file.\n\x1b[0m");
	return (fd);
}

int	ft_cr_open(char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		ft_printf("\x1b[1;31mError opening or creating the file.\n\x1b[0m");
	return (fd);
}

void	ft_close(int fd)
{
	if (fd != -1)
		close(fd);
}
