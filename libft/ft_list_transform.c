/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_transform.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 00:48:58 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/12 00:51:59 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_to_add;

	if (!lst || !new)
		return ;
	last_to_add = ft_lstlast(*lst);
	if (!last_to_add)
		*lst = new;
	else
		last_to_add->next = new;
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	lst->content = NULL;
	free(lst);
	lst = NULL;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ctr;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		ctr = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = ctr;
	}
	*lst = NULL;
}
