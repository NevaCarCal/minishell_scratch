/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:25:54 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/04 19:49:22 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	compose_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

int	gradient(int start, int end, double percent)
{
	return ((int)(start + (end - start) * percent));
}

int	c_red(int colour)
{
	return ((colour >> 16) & 0xFF);
}

int	c_green(int colour)
{
	return ((colour >> 8) & 0xFF);
}

int	c_blue(int colour)
{
	return (colour & 0xFF);
}
