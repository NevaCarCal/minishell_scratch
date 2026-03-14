/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 11:38:50 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/04 18:09:04 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				ctr;
	const unsigned char	*str;

	str = (const unsigned char *)s;
	ctr = 0;
	while (ctr < n)
	{
		if ((unsigned char)c == str[ctr])
			return ((void *)(str + ctr));
		ctr++;
	}
	return (NULL);
}
