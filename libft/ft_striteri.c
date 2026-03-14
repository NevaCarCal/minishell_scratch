/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:13:43 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/04 18:11:52 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	ctr;

	if (!s || !f)
		return ;
	ctr = 0;
	while (s[ctr])
	{
		f(ctr, &s[ctr]);
		ctr++;
	}
}
