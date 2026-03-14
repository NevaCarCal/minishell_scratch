/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:30:01 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/04 18:10:53 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	int	ctr;

	if (!s)
		return ;
	ctr = 0;
	while (s[ctr])
		ctr++;
	write(fd, s, ctr);
	write(fd, "\n", 1);
}
