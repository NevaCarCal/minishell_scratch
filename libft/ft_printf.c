/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:48:58 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/04 18:10:31 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_print_ptr(uintptr_t address)
{
	if (!address)
		return (ft_print_str("(nil)"));
	return (ft_print_str("0x") + print_hex_helper(address));
}

static int	match_format(va_list arg, const char flag)
{
	int	ctr;

	ctr = 0;
	if (flag == '%')
		ctr = ft_print_char('%');
	else if (flag == 'c')
		ctr = ft_print_char((char)va_arg(arg, int));
	else if (flag == 's')
		ctr = ft_print_str(va_arg(arg, char *));
	else if (flag == 'p')
		ctr = ft_print_ptr(va_arg(arg, uintptr_t));
	else if (flag == 'd' || flag == 'i')
		ctr = ft_print_num(va_arg(arg, int));
	else if (flag == 'u')
		ctr = ft_print_unsigned_num(va_arg(arg, unsigned int));
	else if (flag == 'x')
		ctr = print_hex_helper(va_arg(arg, unsigned int));
	else if (flag == 'X')
		ctr = print_hex_helper_uc(va_arg(arg, unsigned int));
	return (ctr);
}

int	ft_printf(char const *kw, ...)
{
	va_list	args;
	int		ctr;
	int		print_ctr;

	va_start(args, kw);
	print_ctr = 0;
	ctr = 0;
	while (kw[ctr])
	{
		if (kw[ctr] != '%')
			print_ctr += ft_print_char(kw[ctr]);
		else if (kw[ctr] == '%')
		{
			ctr++;
			print_ctr += match_format(args, kw[ctr]);
		}
		ctr++;
	}
	return (print_ctr);
}
