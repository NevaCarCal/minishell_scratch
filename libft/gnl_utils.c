/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 09:36:21 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/04 19:24:17 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gstrdup(char *s1)
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

size_t	ft_gstrlen(char *str)
{
	int	ctr;

	ctr = 0;
	while (str[ctr])
		ctr++;
	return (ctr);
}

char	*ft_gsubstr(char *s, unsigned int start, size_t len)
{
	size_t	ctr;
	char	*new_s;

	ctr = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_gstrlen(s))
	{
		new_s = (char *)malloc(1);
		if (new_s == NULL)
			return (NULL);
		new_s[0] = '\0';
		return (new_s);
	}
	if (len > (ft_gstrlen(s) - start))
		len = ft_gstrlen(s) - start;
	new_s = (char *)malloc(sizeof(char) * (len + 1));
	if (new_s == NULL)
		return (NULL);
	while (s[start] && ctr < len)
		new_s[ctr++] = s[start++];
	new_s[ctr] = '\0';
	return (new_s);
}

char	*ft_gstrjoin(char *s1, char *s2)
{
	unsigned int	size;
	unsigned int	ctr;
	char			*new_str;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	size = ft_gstrlen(s1) + ft_gstrlen(s2);
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

char	*ft_gstrchr(char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
