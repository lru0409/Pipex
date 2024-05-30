/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_setup_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:22:45 by rolee             #+#    #+#             */
/*   Updated: 2024/05/30 21:37:35 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	set_files(int argc, char *argv[], t_data *data);
static char	**set_paths(char *env[]);
static int	set_command_list(int argc, char *argv[], char *paths[], t_data *data);
static int	set_pipe(t_data *data);

int	set_data(int argc, char *argv[], char *env[], t_data *data)
{
	if (set_files(argc, argv, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	data->paths = set_paths(env);
	if (!data->paths)
		return (EXIT_FAILURE);
	if (set_command_list(argc, argv, data->paths, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (set_pipe(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	set_files(int argc, char *argv[], t_data *data)
{
	char	*infile_name;
	int		outfile_flag;

	infile_name = argv[1];
	outfile_flag = O_TRUNC;
	if (data->is_heredoc)
	{
		infile_name = TEMP_FILE;
		outfile_flag = O_APPEND;
	}
	data->infile_fd = open(infile_name, O_RDONLY);
	if (data->infile_fd == -1)
	{
		perror(infile_name);
		return (EXIT_FAILURE);
	}
	data->outfile_fd = open(argv[argc-1], O_WRONLY | O_CREAT | outfile_flag, 0644);
	if (data->outfile_fd == -1)
	{
		perror(argv[argc-1]);
		return (EXIT_FAILURE);
	}
	return (EXIT_FAILURE);
}

static char	**set_paths(char *env[])
{
	int		idx;
	char	*path_str;
	char	**paths;

	idx = 0;
	while (env[idx])
	{
		if (ft_strncmp("PATH", env[idx], 4) == 0)
			break ;
		idx++;
	}
	path_str = ft_substr(env[idx], 5, ft_strlen(env[idx]) - 5);
	if (!path_str)
		return (NULL);
	paths = ft_split(path_str, ':');
	free(path_str);
	return (paths);
}

static int	set_command_list(int argc, char *argv[], char *paths[], t_data *data)
{
	int			index;
	t_command	*command;

	index = 2;
	if (data->is_heredoc)
		index = 3;
	data->command_count = argc - index - 1;
	while (index < index + data->command_count)
	{
		command = set_command(argv[index], paths);
		if (!command)
			return (EXIT_FAILURE);
		add_command(&data->command_list, command);
		index++;
	}
	return (EXIT_SUCCESS);
}

static int	set_pipe(t_data *data)
{
	int	index;

	data->pipe = (int **)malloc(sizeof(int *) * (data->command_count - 1));
	if (!data->pipe)
		return (EXIT_FAILURE);
	ft_memset(data->pipe, 0, sizeof(int *) * (data->command_count - 1)); // TODO : NULL 초기화 되나?
	index = 0;
	while (index < data->command_count - 1)
	{
		data->pipe[index] = (int *)malloc(sizeof(int) * 2);
		if (!data->pipe[index])
			return (EXIT_FAILURE); // TODO : 메모리 누수 없을지 보자
		ft_memset(data->pipe[index], -1, sizeof(int) * 2); // TODO : -1로 초기화되나?
		if (pipe(data->pipe[index]) == -1)
			return (EXIT_FAILURE);
		index++;
	}
	return (EXIT_SUCCESS);
}
