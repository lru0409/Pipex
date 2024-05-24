/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:10:29 by rolee             #+#    #+#             */
/*   Updated: 2024/03/20 17:12:15 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	alloc_len;
	char			*result;
	unsigned int	idx;

	alloc_len = ft_strlen(s);
	result = (char *)malloc(alloc_len + 1);
	if (!result)
		return (NULL);
	idx = 0;
	while (s[idx])
	{
		result[idx] = f(idx, s[idx]);
		idx++;
	}
	result[idx] = 0;
	return (result);
}
