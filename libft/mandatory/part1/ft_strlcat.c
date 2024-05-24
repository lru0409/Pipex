/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:27:52 by rolee             #+#    #+#             */
/*   Updated: 2024/03/20 16:57:00 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_idx;
	size_t	src_idx;

	dst_idx = 0;
	while (dst[dst_idx] && dst_idx < dstsize)
		dst_idx++;
	src_idx = 0;
	while (src[src_idx] && dst_idx + src_idx + 1 < dstsize)
	{
		dst[dst_idx + src_idx] = src[src_idx];
		src_idx++;
	}
	if (dst_idx < dstsize)
		dst[dst_idx + src_idx] = 0;
	return (dst_idx + ft_strlen(src));
}
