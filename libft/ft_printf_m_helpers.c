/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_m_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:48:58 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/04 18:10:08 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_write(char *str, int out)
{
	write(out, str, ft_strlen(str));
	return (ft_strlen(str));
}

int	ft_print_str(const char	*s)
{
	int	ctr;

	ctr = 0;
	if (!s)
		return (ft_print_str("(null)"));
	while (s[ctr])
		ctr++;
	if (write(1, s, ctr) == -1)
		return (-1);
	return (ctr);
}

int	ft_print_char(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	else
		return (1);
}

int	ft_print_num(int n)
{
	char	n_to_c;
	int		ctr;

	ctr = 0;
	if (n == -2147483648)
		return (ft_print_str("-2147483648"));
	if (n == 0)
		return (ft_print_str("0"));
	if (n < 0)
	{
		ctr += ft_print_char('-');
		n = -n;
	}
	if (n >= 10)
		ctr += ft_print_num(n / 10);
	n_to_c = (char)(n % 10) + '0';
	ctr += ft_print_char(n_to_c);
	return (ctr);
}

int	ft_print_unsigned_num(unsigned int n)
{
	char	n_to_c;
	int		ctr;
	int		stack[11];
	int		top;

	ctr = 0;
	top = 0;
	if (n == 0)
		return (ft_print_num(0));
	while (n > 0)
	{
		stack[top++] = n % 10;
		n /= 10;
	}
	while (top > 0)
	{
		n_to_c = stack[--top] + '0';
		if (write(1, &n_to_c, 1) == -1)
			return (-1);
		ctr++;
	}
	return (ctr);
}
