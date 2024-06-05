/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:16:58 by rolee             #+#    #+#             */
/*   Updated: 2024/06/05 19:34:01 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static t_data	*init_data(void);
static int		check_argc(int argc, int is_heredoc);
static int		end(int ret, t_data *data);

int	main(int argc, char *argv[], char *env[])
{
	t_data	*data;

	data = init_data();
	if (manage_heredoc(argv, data) == EXIT_FAILURE)
		return (end(EXIT_FAILURE, data));
	if (check_argc(argc, data->is_heredoc) == EXIT_FAILURE)
		return (end(EXIT_FAILURE, data));
	if (set_data(argc, argv, env, data) == EXIT_FAILURE)
		return (end(EXIT_FAILURE, data));
	execute_commands(data, env);
	if (wait_processes(data) == EXIT_FAILURE)
		return (end(EXIT_FAILURE, data));
	return (end(EXIT_SUCCESS, data));
}

static t_data	*init_data(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->infile_fd = -1;
	data->outfile_fd = -1;
	data->is_heredoc = FALSE;
	data->paths = NULL;
	data->command_count = 0;
	data->command_list = NULL;
	data->pipe = NULL;
	return (data);
}

static int	check_argc(int argc, int is_heredoc)
{
	if ((is_heredoc && argc < 5) || (!is_heredoc && argc < 4))
	{
		ft_putendl_fd("Invalid Argument.", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static int	end(int ret, t_data *data)
{
	clear_data(data);
	return (ret);
}
