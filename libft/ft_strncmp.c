/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 15:23:27 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/04 18:12:40 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	ctr;

	ctr = 0;
	while (ctr < n)
	{
		if (s1[ctr] != s2[ctr] || s1[ctr] == '\0' || s2[ctr] == '\0')
			return ((unsigned char)s1[ctr] - (unsigned char)s2[ctr]);
		ctr++;
	}
	return (0);
}
