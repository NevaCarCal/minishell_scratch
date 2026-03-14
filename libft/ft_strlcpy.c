/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 01:06:35 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/04 18:12:13 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	ctr;
	size_t	len;

	len = 0;
	ctr = 0;
	while (src[len])
		len++;
	if (size > 0)
	{
		while (src[ctr] && ctr < size - 1)
		{
			dest[ctr] = src[ctr];
			ctr++;
		}
		dest[ctr] = '\0';
	}
	return (len);
}
