/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:41:34 by rolee             #+#    #+#             */
/*   Updated: 2024/03/20 17:30:20 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current_node;
	t_list	*new_node;
	t_list	*result_lst;

	current_node = lst;
	result_lst = NULL;
	while (current_node)
	{
		new_node = malloc(sizeof(t_list));
		if (!new_node)
		{
			ft_lstclear(&result_lst, del);
			return (NULL);
		}
		new_node->content = (*f)(current_node->content);
		new_node->next = NULL;
		ft_lstadd_back(&result_lst, new_node);
		current_node = current_node->next;
	}
	return (result_lst);
}
