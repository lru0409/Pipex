/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:21:23 by rolee             #+#    #+#             */
/*   Updated: 2024/05/24 13:30:09 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int			set_files(char *argv[], t_data *data);
static t_command	*set_command(char *cmd_argv, char *env[]);
static t_command	*create_command();

t_data	*create_data()
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->infile_fd = -1;
	data->outfile_fd = -1;
	data->cmd1 = NULL;
	data->cmd2 = NULL;
	// TODO : pipe 초기화?
	return (data);
}

int	set_data(char *argv[], char *env[], t_data *data)
{
	if (set_files(argv, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	data->cmd1 = set_command(argv[1], env);
	if (!data->cmd1)
		return (EXIT_FAILURE);
	data->cmd2 = set_command(argv[4], env);
	if (!data->cmd1)
		return (EXIT_FAILURE);
	// TODO : pipe 함수 여기서 하는 거 맞을까?
	return (EXIT_FAILURE);
}

static int	set_files(char *argv[], t_data *data)
{
	data->infile_fd = open(argv[1], O_RDONLY);
	if (data->infile_fd == -1)
		return (EXIT_FAILURE); // TODO: perror 해야 할까?
	data->outfile_fd = open(argv[4], O_WRONLY); // 다른 인자들 필요 없을까?
	if (data->outfile_fd == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static t_command	*set_command(char *cmd_argv, char *env[])
{
	t_command	*cmd;

	cmd = create_command();
	if (!cmd)
		return (NULL);
	cmd->argv = ft_split(cmd_argv, ' '); // TODO : 빈문자열 "" 이 들어오면 어떻게 되지? 괜찮나??
	if (!cmd->argv)
		return (NULL);
	if (cmd->argv[0][0] == '/')
		cmd->path = ft_strdup(cmd->argv[0]);
	// else TODO : get_command_path 구현하기
	// 	cmd->path = get_command_path();
	env = NULL;
	if (!cmd->path)
		return (NULL);
	return (cmd);
}

static t_command	*create_command()
{
	t_command	*cmd;

	cmd = (t_command *)malloc(sizeof(t_command));
	if (!cmd)
		return (NULL);
	cmd->path = NULL;
	cmd->argv = NULL;
	return (cmd);
}
