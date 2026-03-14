/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:33:56 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/04 18:05:38 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	mem_size;
	size_t	ctr;
	void	*mem_ptr;

	mem_size = nmemb * size;
	ctr = 0;
	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	mem_ptr = malloc(mem_size);
	if (!mem_ptr)
		return (NULL);
	while (ctr < mem_size)
	{
		((unsigned char *)mem_ptr)[ctr] = 0;
		ctr++;
	}
	return (mem_ptr);
}
