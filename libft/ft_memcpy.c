/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 00:37:20 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/04 18:09:25 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d_ptr;
	unsigned char const	*s_ptr;

	if (!dest && !src && n > 0)
		return (NULL);
	d_ptr = (unsigned char *)dest;
	s_ptr = (unsigned char const *)src;
	while (n--)
		*d_ptr++ = *s_ptr++;
	return (dest);
}
