/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:21:23 by rolee             #+#    #+#             */
/*   Updated: 2024/06/05 19:27:45 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int			set_files(char *argv[], t_data *data);
static char			**set_paths(char *env[]);
static t_command	*set_command(char *cmd_argv, char *paths[]);

int	set_data(char *argv[], char *env[], t_data *data)
{
	if (set_files(argv, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	data->paths = set_paths(env);
	if (!data->paths)
		return (EXIT_FAILURE);
	data->cmd1 = set_command(argv[2], data->paths);
	if (!data->cmd1)
		return (EXIT_FAILURE);
	data->cmd2 = set_command(argv[3], data->paths);
	if (!data->cmd2)
		return (EXIT_FAILURE);
	if (pipe(data->pipe) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	set_files(char *argv[], t_data *data)
{
	data->infile_fd = open(argv[1], O_RDONLY);
	if (data->infile_fd == -1)
	{
		perror(argv[1]);
		return (EXIT_FAILURE);
	}
	data->outfile_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (data->outfile_fd == -1)
	{
		perror(argv[4]);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
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

static t_command	*set_command(char *cmd_argv, char *paths[])
{
	t_command	*cmd;

	cmd = init_command();
	if (!cmd)
		return (NULL);
	cmd->argv = ft_split(cmd_argv, ' ');
	if (!cmd->argv)
		return (NULL);
	if (cmd->argv[0][0] == '/')
		cmd->path = ft_strdup(cmd->argv[0]);
	else
		cmd->path = get_command_path(cmd->argv[0], paths);
	if (!cmd->path)
	{
		free_strs(cmd->argv);
		free(cmd);
		return (NULL);
	}
	return (cmd);
}
