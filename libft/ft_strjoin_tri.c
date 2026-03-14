/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_tri.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 21:54:32 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/10 22:56:52 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_tri(const char *s1, const char *s2, const char *s3)
{
	char	*new_str;
	size_t	l1;
	size_t	l2;
	size_t	l3;

	if (!s1 || !s2 || !s3)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	l3 = ft_strlen(s3);
	new_str = (char *)malloc(sizeof(char) * (l1 + l2 + l3 + 1));
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s1, l1);
	ft_memcpy(new_str + l1, s2, l2);
	ft_memcpy(new_str + l1 + l2, s3, l3);
	new_str[l1 + l2 + l3] = '\0';
	return (new_str);
}
