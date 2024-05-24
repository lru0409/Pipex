/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:55:46 by rolee             #+#    #+#             */
/*   Updated: 2024/05/10 19:18:44 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		idx;

	new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_str)
		return (NULL);
	new_str[0] = 0;
	idx = 0;
	while (s1 && *s1)
	{
		new_str[idx++] = *s1;
		s1++;
	}
	while (s2 && *s2)
	{
		new_str[idx++] = *s2;
		s2++;
	}
	new_str[idx] = 0;
	return (new_str);
}
