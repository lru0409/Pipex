/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:15:33 by rolee             #+#    #+#             */
/*   Updated: 2024/03/20 16:59:41 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	idx;

	idx = ft_strlen(s);
	while (idx >= 0)
	{
		if (s[idx] == (char)c)
			return (&((char *)s)[idx]);
		idx--;
	}
	return (NULL);
}
