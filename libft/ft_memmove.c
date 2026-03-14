/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 00:49:06 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/04 18:09:36 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d_ptr;
	const unsigned char	*s_ptr;

	if (!dest && !src && n > 0)
		return (NULL);
	d_ptr = (unsigned char *)dest;
	s_ptr = (const unsigned char *)src;
	if (d_ptr > s_ptr && d_ptr < s_ptr + n)
	{
		d_ptr += n;
		s_ptr += n;
		while (n--)
			*(--d_ptr) = *(--s_ptr);
	}
	else
	{
		while (n--)
			*d_ptr++ = *s_ptr++;
	}
	return (dest);
}
