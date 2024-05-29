/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:25:06 by rolee             #+#    #+#             */
/*   Updated: 2024/05/29 20:48:36 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	end(int ret, t_data *data);

int	main(int argc, char *argv[], char *env[])
{
	t_data *data;

	if (argc != 5)
	{
		ft_putendl_fd("Invalid Argument.", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	data = create_data();
	if (!data)
		return (EXIT_FAILURE);
	if (set_data(argv, env, data) == EXIT_FAILURE)
		return (end(EXIT_FAILURE, data));
	execute_first_command(data, env);
	execute_second_command(data, env);
	if (wait_processes() == EXIT_FAILURE)
		return (end(EXIT_FAILURE, data));

	return (end(EXIT_SUCCESS, data));
}

static int	end(int ret, t_data *data)
{
	clear_data(data);
	return (ret);
}
