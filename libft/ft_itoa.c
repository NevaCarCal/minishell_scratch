/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 00:26:19 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/04 18:07:39 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>

static int	int_characters(int n)
{
	if (n == INT_MIN)
		return (1 + int_characters(INT_MAX));
	if (n < 0)
		return (1 + int_characters(-n));
	if (n < 10)
		return (1);
	return (1 + int_characters(n / 10));
}

char	*ft_itoa(int n)
{
	char			*str;
	int				n_size;
	int				ctr;
	unsigned int	num;

	ctr = 0;
	n_size = int_characters(n);
	str = (char *)malloc(sizeof(char) * (n_size + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[ctr++] = '-';
		num = (unsigned int)(-n);
	}
	else
		num = (unsigned int)n;
	str[n_size] = '\0';
	while (n_size-- > ctr)
	{
		str[n_size] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
