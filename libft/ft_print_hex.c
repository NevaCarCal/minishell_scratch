/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:48:58 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/04 18:10:23 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_hex_helper(uintptr_t address)
{
	int	digit;

	digit = 0;
	if (address >= 16)
		digit += print_hex_helper(address / 16);
	address = address % 16;
	if (address < 10)
		digit += ft_print_char((char)('0' + address));
	else
		digit += ft_print_char((char)('a' + address - 10));
	return (digit);
}

int	print_hex_helper_uc(unsigned int address)
{
	int	digit;

	digit = 0;
	if (address >= 16)
		digit += print_hex_helper_uc(address / 16);
	address = address % 16;
	if (address < 10)
		digit += ft_print_char((char)('0' + address));
	else
		digit += ft_print_char((char)('A' + address - 10));
	return (digit);
}
