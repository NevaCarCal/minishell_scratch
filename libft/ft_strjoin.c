/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:25:01 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/04 18:11:59 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	ft_strlen(const char *str)
{
	unsigned int	ctr;

	ctr = 0;
	while (str[ctr])
		ctr++;
	return (ctr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	size;
	unsigned int	ctr;
	char			*new_str;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	size = ft_strlen(s1) + ft_strlen(s2);
	ctr = 0;
	new_str = (char *)malloc(sizeof(char) * (size + 1));
	if (new_str == NULL)
		return (NULL);
	if (size == 0)
	{
		new_str[0] = '\0';
		return (new_str);
	}
	while (*s1)
		new_str[ctr++] = *s1++;
	while (*s2)
		new_str[ctr++] = *s2++;
	new_str[ctr] = '\0';
	return (new_str);
}
