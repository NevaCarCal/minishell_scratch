/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 19:45:07 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/04 21:03:39 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_hextoi(char *hex_str, int n)
{
	int		base_ten_val;
	int		val;
	char	c;

	val = 0;
	if (hex_str[n] == '0' && (hex_str[n + 1] == 'x' || hex_str[n + 1] == 'X'))
		n += 2;
	while (hex_str[n] != '\0')
	{
		c = hex_str[n];
		if (c >= '0' && c <= '9')
			base_ten_val = c - '0';
		else if (c >= 'a' && c <= 'f')
			base_ten_val = c - 'a' + 10;
		else if (c >= 'A' && c <= 'F')
			base_ten_val = c - 'A' + 10;
		else
			return (val);
		val = val * 16 + base_ten_val;
		n++;
	}
	return (val);
}
