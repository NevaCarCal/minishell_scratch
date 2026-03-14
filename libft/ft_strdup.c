/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:14:22 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/04 18:11:37 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	ctr;
	char	*ptr;
	char	*ptr2;

	ctr = 0;
	while (s1[ctr])
		ctr++;
	ptr = (char *)malloc((ctr + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	ptr2 = ptr;
	while (*s1)
		*ptr++ = *s1++;
	*ptr = '\0';
	return (ptr2);
}
