/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:25:06 by rolee             #+#    #+#             */
/*   Updated: 2024/05/24 13:27:29 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	end(int ret, t_data *data);

int	main(int argc, char *argv[], char *env[])
{
	t_data *data;

	if (argc != 5)
	{
		// TODO : 오류 출력
		exit(EXIT_FAILURE);
	}
	data = create_data();
	if (!data)
		return (EXIT_FAILURE);
	if (set_data(argv, env, data) == EXIT_FAILURE)
		return (end(EXIT_FAILURE, data));
	
	// TODO

	return (end(EXIT_SUCCESS, data));
}

static int	end(int ret, t_data *data) // TODO : 에러메시지?
{
	clear_data(data);
	return (ret);
}
