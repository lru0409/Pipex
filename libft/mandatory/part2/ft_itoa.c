/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:57:13 by rolee             #+#    #+#             */
/*   Updated: 2024/03/20 17:19:15 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	get_alloc_size(long long n);
static char	*return_result(long long n, char *result);
static char	*ft_strcat(char *dest, char c);

char	*ft_itoa(int n)
{
	long long	nbr;
	int			alloc_size;
	char		*result;

	nbr = (long long)n;
	alloc_size = get_alloc_size(nbr);
	result = (char *)malloc(alloc_size + 1);
	if (!result)
		return (NULL);
	if (nbr < 0)
	{
		result[0] = '-';
		result[1] = '\0';
		return (return_result(-nbr, result));
	}
	else
	{
		result[0] = '\0';
		return (return_result(nbr, result));
	}
}

static int	get_alloc_size(long long n)
{
	long long	div;
	int			size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		div = -n;
		size++;
	}
	else
		div = n;
	while (div > 0)
	{
		div = div / 10;
		size++;
	}
	return (size);
}

static char	*return_result(long long n, char *result)
{
	if (n > 9)
	{
		return_result(n / 10, result);
		result = ft_strcat(result, (n % 10) + '0');
	}
	else
	{
		result = ft_strcat(result, n + '0');
	}
	return (result);
}

static char	*ft_strcat(char *dest, char c)
{
	int	i;

	i = 0;
	while (dest[i])
		i++;
	dest[i] = c;
	dest[i + 1] = 0;
	return (dest);
}
