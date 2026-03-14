/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:39:19 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/04 18:13:21 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static unsigned int	ft_strlen(const char *str)
{
	unsigned int	ctr;

	ctr = 0;
	while (str[ctr])
		ctr++;
	return (ctr);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	ctr;
	char	*new_s;

	ctr = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		new_s = (char *)malloc(1);
		if (new_s == NULL)
			return (NULL);
		new_s[0] = '\0';
		return (new_s);
	}
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	new_s = (char *)malloc(sizeof(char) * (len + 1));
	if (new_s == NULL)
		return (NULL);
	while (s[start] && ctr < len)
		new_s[ctr++] = s[start++];
	new_s[ctr] = '\0';
	return (new_s);
}
