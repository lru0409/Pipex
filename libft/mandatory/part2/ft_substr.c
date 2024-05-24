/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:09:48 by rolee             #+#    #+#             */
/*   Updated: 2024/03/20 13:26:21 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	alloc_size;
	unsigned int	idx;

	if (start >= ft_strlen(s))
	{
		substr = ft_strdup("");
		return (substr);
	}
	alloc_size = 0;
	while (alloc_size < len && s[start + alloc_size])
		alloc_size++;
	substr = (char *)malloc(alloc_size + 1);
	if (!substr)
		return (NULL);
	idx = 0;
	while (idx < len && s[start + idx])
	{
		substr[idx] = s[start + idx];
		idx++;
	}
	substr[idx] = 0;
	return (substr);
}
