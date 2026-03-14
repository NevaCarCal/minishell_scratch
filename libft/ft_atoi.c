/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 11:40:42 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/04 17:17:04 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long int	ctr;
	long int	sign;
	long int	result;

	sign = 1;
	ctr = 0;
	result = 0;
	while (ft_isspace(nptr[ctr]))
		ctr++;
	if (nptr[ctr] == '-' || nptr[ctr] == '+')
	{
		if (nptr[ctr] == '-')
			sign = -1;
		ctr++;
	}
	while (nptr[ctr] >= '0' && nptr[ctr] <= '9')
	{
		result = (result * 10) + (nptr[ctr] - '0');
		ctr++;
	}
	return ((int)(result * sign));
}

static int	iof_check(long int num, int to_add, int sign)
{
	if (sign >= 0)
	{
		if (num > (INT_MAX - to_add) / 10)
			return (1);
		return (0);
	}
	else
	{
		if (num > ((long)INT_MIN * -1 - to_add) / 10)
			return (1);
		return (0);
	}
}

int	ft_safe_atoi(const char *nptr, int *status)
{
	long int	ctr;
	long int	sign;
	long int	result;

	sign = 1;
	ctr = 0;
	result = 0;
	while (ft_isspace(nptr[ctr]))
		ctr++;
	if (nptr[ctr] == '-' || nptr[ctr] == '+')
	{
		if (nptr[ctr] == '-')
			sign = -1;
		ctr++;
	}
	while (nptr[ctr] >= '0' && nptr[ctr] <= '9')
	{
		if (iof_check(result, (nptr[ctr] - '0'), sign))
			*status = -1;
		result = (result * 10) + (nptr[ctr] - '0');
		ctr++;
	}
	if (*status != 0)
		return (0);
	return ((int)(result * sign));
}
