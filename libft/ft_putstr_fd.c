/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:17:58 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/04 18:11:13 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_fd(char *s, int fd)
{
	int	ctr;

	if (!s)
		return ;
	ctr = 0;
	while (s[ctr])
		ctr++;
	write(fd, s, ctr);
}
