/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 01:24:02 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/04 18:12:37 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	ctr;
	char			*f_str;

	if (!s || !f)
		return (NULL);
	ctr = 0;
	len = 0;
	while (s[len])
		len++;
	f_str = (char *)malloc(sizeof(char) * (len + 1));
	if (!f_str)
		return (NULL);
	while (ctr < len)
	{
		f_str[ctr] = f(ctr, s[ctr]);
		ctr++;
	}
	f_str[ctr] = '\0';
	return (f_str);
}
