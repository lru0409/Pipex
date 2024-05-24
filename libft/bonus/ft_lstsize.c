/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:51:20 by rolee             #+#    #+#             */
/*   Updated: 2024/03/20 13:25:36 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current_node;
	int		size;

	current_node = lst;
	size = 0;
	while (current_node)
	{
		size++;
		current_node = current_node->next;
	}
	return (size);
}
