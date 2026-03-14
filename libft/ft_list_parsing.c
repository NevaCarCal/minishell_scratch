/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 00:40:28 by ncarrera          #+#    #+#             */
/*   Updated: 2025/07/13 23:51:37 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ctr;

	if (!lst || !f)
		return ;
	ctr = lst;
	while (ctr)
	{
		f(ctr->content);
		ctr = ctr->next;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next)
		last = last->next;
	return (last);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ctr;
	t_list	*item_ctr;
	t_list	*i;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	ctr = NULL;
	i = lst;
	while (i)
	{
		content = f(i->content);
		item_ctr = ft_lstnew(content);
		if (item_ctr == NULL)
		{
			del(content);
			ft_lstclear(&ctr, del);
			return (NULL);
		}
		ft_lstadd_back(&ctr, item_ctr);
		i = i->next;
	}
	return (ctr);
}

int	ft_lstsize(t_list *lst)
{
	t_list	*i;
	int		ctr;

	if (!lst)
		return (0);
	i = lst;
	ctr = 0;
	while (i)
	{
		i = i->next;
		ctr++;
	}
	return (ctr);
}

int	ft_duplicate_check(t_list *lst, int num)
{
	t_list	*c_elem;

	c_elem = lst;
	while (c_elem)
	{
		if (*(int *)(c_elem->content) == num)
			return (1);
		c_elem = c_elem->next;
	}
	return (0);
}
