/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:51:22 by rolee             #+#    #+#             */
/*   Updated: 2024/03/20 16:51:15 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		if (((unsigned char *)s1)[idx] != ((unsigned char *)s2)[idx])
			break ;
		idx++;
	}
	if (idx == n)
		return (0);
	return (((unsigned char *)s1)[idx] - ((unsigned char *)s2)[idx]);
}
