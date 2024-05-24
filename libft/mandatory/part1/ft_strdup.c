/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 20:34:03 by rolee             #+#    #+#             */
/*   Updated: 2024/03/20 17:03:54 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		s_len;
	int		idx;

	s_len = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * (s_len + 1));
	if (!ptr)
		return (NULL);
	idx = 0;
	while (idx < s_len)
	{
		ptr[idx] = s1[idx];
		idx++;
	}
	ptr[idx] = 0;
	return (ptr);
}
