/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 22:13:31 by alcaroff          #+#    #+#             */
/*   Updated: 2017/11/16 02:21:45 by alcaroff         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clean(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*start;

	if (lst == NULL)
		return (NULL);
	new = ft_lstnew(lst->content, lst->content_size);
	if (new == NULL)
		return (NULL);
	new = (*f)(new);
	start = new;
	while (lst->next)
	{
		new->next = ft_lstnew(lst->next->content, lst->next->content_size);
		new->next = (*f)(new->next);
		if (new->next == NULL)
		{
			clean(start);
			return (NULL);
		}
		new = new->next;
		lst = lst->next;
	}
	return (start);
}
