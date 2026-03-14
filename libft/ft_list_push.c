/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 21:33:28 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/13 23:50:47 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push(t_list **s_list, t_list **d_list, char *str)
{
	t_list	*list_to_move;

	if (!s_list || !(*s_list))
		return ;
	list_to_move = *s_list;
	*s_list = (*s_list)->next;
	list_to_move->next = NULL;
	ft_lstadd_front(d_list, list_to_move);
	ft_printf("%s", str);
}
