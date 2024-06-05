/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:25:06 by rolee             #+#    #+#             */
/*   Updated: 2024/06/05 19:27:31 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int		check_argc(int argc);
static t_data	*init_data(void);
static int		end(int ret, t_data *data);

int	main(int argc, char *argv[], char *env[])
{
	t_data	*data;

	if (check_argc(argc) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	data = init_data();
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

static int	check_argc(int argc)
{
	if (argc != 5)
	{
		ft_putendl_fd("Invalid Argument.", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static t_data	*init_data(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->infile_fd = -1;
	data->outfile_fd = -1;
	data->paths = NULL;
	data->cmd1 = NULL;
	data->cmd2 = NULL;
	return (data);
}

static int	end(int ret, t_data *data)
{
	clear_data(data);
	return (ret);
}
