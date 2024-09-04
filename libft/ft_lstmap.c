/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanhern <juanhern@student.42madrid.es>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:13:37 by juanhern          #+#    #+#             */
/*   Updated: 2024/04/12 13:47:12 by juanhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_delete_list(t_list *head, void *mapped_content,
		void (*del)(void *))
{
	del(mapped_content);
	ft_lstclear(&head, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*current;
	void	*mapped_content;

	if (lst && del && f)
	{
		mapped_content = f(lst->content);
		head = ft_lstnew(mapped_content);
		if (head == NULL)
			head = ft_delete_list(head, mapped_content, del);
		lst = lst->next;
		while (lst && head)
		{
			mapped_content = f(lst->content);
			current = ft_lstnew(mapped_content);
			if (!current)
				head = ft_delete_list(head, mapped_content, del);
			ft_lstadd_back(&head, current);
			lst = lst->next;
		}
		return (head);
	}
	return (NULL);
}
