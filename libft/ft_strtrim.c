/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 14:48:35 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/04 18:13:15 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static int	ft_is_in_set(const char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	ft_strlen(const char *str)
{
	int	ctr;

	ctr = 0;
	while (str[ctr])
		ctr++;
	return (ctr);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		s_ctr;
	int		e_ctr;
	int		new_len;
	char	*new_str;

	if (!s1 || !set)
		return (NULL);
	s_ctr = 0;
	e_ctr = ft_strlen(s1) - 1;
	while (s1[s_ctr] && ft_is_in_set(s1[s_ctr], set))
		s_ctr++;
	while (e_ctr >= s_ctr && ft_is_in_set(s1[e_ctr], set))
		e_ctr--;
	new_len = e_ctr - s_ctr + 1;
	new_str = (char *)malloc(sizeof(char) * (new_len + 1));
	if (new_str == NULL)
		return (NULL);
	e_ctr = 0;
	while (e_ctr < new_len)
	{
		new_str[e_ctr] = s1[s_ctr + e_ctr];
		e_ctr++;
	}
	new_str[new_len] = '\0';
	return (new_str);
}
