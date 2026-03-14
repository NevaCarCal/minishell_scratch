/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 01:25:06 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/04 18:12:02 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	ctr;
	size_t	lctr;

	ctr = 0;
	lctr = 0;
	while (lctr < size && dest[lctr])
		lctr++;
	while ((1 + ctr + lctr) < size && src[ctr])
	{
		dest[ctr + lctr] = src[ctr];
		ctr++;
	}
	if (lctr != size)
		dest[ctr + lctr] = '\0';
	return (lctr + ft_strlen(src));
}
