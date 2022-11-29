/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgelin <cgelin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:54:59 by cgelin            #+#    #+#             */
/*   Updated: 2022/11/16 15:58:22 by cgelin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cpy;
	t_list	*new;

	if (!lst || !del || !f)
		return (NULL);
	new = ft_lstnew((*f)(lst->content));
	if (!new)
		return (NULL);
	cpy = new;
	while (lst->next)
	{
		lst = lst->next;
		cpy->next = ft_lstnew((f)(lst->content));
		if (!cpy->next)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		cpy = cpy->next;
	}
	return (new);
}
