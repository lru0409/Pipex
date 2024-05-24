/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:16:24 by rolee             #+#    #+#             */
/*   Updated: 2024/04/24 20:45:32 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

long long	ft_atoi(const char *str)
{
	int			idx;
	int			sign;
	long long	num;

	idx = 0;
	sign = 1;
	while (str[idx] == 32 || (9 <= str[idx] && str[idx] <= 13))
		idx++;
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			sign *= -1;
		idx++;
	}
	num = 0;
	while (ft_isdigit(str[idx]))
	{
		num = (10 * num) + str[idx] - '0';
		idx++;
	}
	return (num * sign);
}
