/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:03:48 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/16 00:51:05 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_swap(t_list **s_list, char *str)
{
	t_list	*first_elem;
	t_list	*sec_elem;

	if (!s_list || !(*s_list) || !((*s_list)->next))
		return ;
	first_elem = *s_list;
	sec_elem = (*s_list)->next;
	first_elem->next = sec_elem->next;
	sec_elem->next = first_elem;
	*s_list = sec_elem;
	if (str)
		ft_printf("%s", str);
}
