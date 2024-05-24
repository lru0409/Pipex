/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:23:10 by rolee             #+#    #+#             */
/*   Updated: 2024/03/20 16:48:15 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	idx;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst < src)
	{
		idx = 0;
		while (idx < (int)len)
		{
			((unsigned char *)dst)[idx] = ((unsigned char *)src)[idx];
			idx++;
		}
	}
	else if (src < dst)
	{
		idx = (int)len - 1;
		while (idx >= 0)
		{
			((unsigned char *)dst)[idx] = ((unsigned char *)src)[idx];
			idx--;
		}
	}
	return (dst);
}
