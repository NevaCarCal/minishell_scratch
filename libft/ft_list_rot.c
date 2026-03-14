/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:19:56 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/13 23:51:10 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_rot(t_list **s_list, char *str)
{
	t_list	*first_elem;
	t_list	*sec_elem;

	if (!s_list || !(*s_list) || !((*s_list)->next))
		return ;
	first_elem = *s_list;
	sec_elem = (*s_list)->next;
	*s_list = sec_elem;
	first_elem->next = NULL;
	ft_lstadd_back(s_list, first_elem);
	ft_printf("%s", str);
}

void	ft_list_rev_rot(t_list **s_list, char *str)
{
	t_list	*last_elem;
	t_list	*slast_elem;

	if (!s_list || !(*s_list) || !((*s_list)->next))
		return ;
	last_elem = *s_list;
	while (last_elem->next)
	{
		slast_elem = last_elem;
		last_elem = last_elem->next;
	}
	slast_elem->next = NULL;
	ft_lstadd_front(s_list, last_elem);
	ft_printf("%s", str);
}
