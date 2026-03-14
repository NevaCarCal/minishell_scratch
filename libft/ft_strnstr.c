/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 00:46:44 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/04 18:12:52 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	ctr;
	size_t	i;

	if (!little[0])
		return ((char *)big);
	if (len == 0)
		return (NULL);
	ctr = 0;
	while (big[ctr] && ctr < len)
	{
		i = 0;
		while (big[ctr + i] == little[i] && (ctr + i) < len)
		{
			i++;
			if (little[i] == '\0')
				return ((char *)&big[ctr]);
		}
		ctr++;
	}
	return (NULL);
}
