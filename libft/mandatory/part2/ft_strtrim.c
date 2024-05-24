/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 17:33:40 by rolee             #+#    #+#             */
/*   Updated: 2024/03/20 13:26:21 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		front_idx;
	int		behind_idx;
	char	*result;

	front_idx = 0;
	while (ft_strchr(set, s1[front_idx]) && s1[front_idx])
		front_idx++;
	behind_idx = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[behind_idx]) && behind_idx >= 0)
		behind_idx--;
	if (front_idx > behind_idx)
		return (ft_strdup(""));
	result = (char *)malloc(behind_idx - front_idx + 2);
	if (!result)
		return (NULL);
	ft_strlcpy(result, &s1[front_idx], behind_idx - front_idx + 2);
	return (result);
}
