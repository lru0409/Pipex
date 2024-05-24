/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:51:11 by rolee             #+#    #+#             */
/*   Updated: 2024/03/20 17:02:58 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hs_idx;
	size_t	nd_idx;

	if (needle[0] == 0)
		return ((char *)haystack);
	hs_idx = 0;
	while (hs_idx < len)
	{
		nd_idx = 0;
		while (needle[nd_idx])
		{
			if (haystack[hs_idx + nd_idx] == 0)
				return (NULL);
			if (hs_idx + nd_idx >= len)
				return (NULL);
			if (haystack[hs_idx + nd_idx] != needle[nd_idx])
				break ;
			nd_idx++;
		}
		if (needle[nd_idx] == 0)
			return ((char *)haystack + hs_idx);
		hs_idx++;
	}
	return (NULL);
}
