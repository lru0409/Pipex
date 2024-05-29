/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:25:06 by rolee             #+#    #+#             */
/*   Updated: 2024/05/28 20:17:05 by rolee            ###   ########.fr       */
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

	// printf("input: %d, output: %d\n", data->infile_fd, data->outfile_fd);
	// printf("path1: %s, path2: %s\n", data->cmd1->path, data->cmd2->path);
	// int idx = 0;
	// printf("cmd1: ");
	// while ((data->cmd1->argv)[idx])
	// 	printf("%s ", (data->cmd1->argv)[idx++]);
	// printf("\n");
	// idx = 0;
	// printf("cmd2: ");
	// while ((data->cmd2->argv)[idx])
	// 	printf("%s ", (data->cmd2->argv)[idx++]);
	// printf("\n");

	execute_first_command(data, env);
	execute_second_command(data, env);
	wait_processes();

	return (end(EXIT_SUCCESS, data));
}

static int	end(int ret, t_data *data) // TODO : 에러메시지?
{
	clear_data(data);
	return (ret);
}
