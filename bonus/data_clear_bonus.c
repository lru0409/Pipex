/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_clear_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:21:01 by rolee             #+#    #+#             */
/*   Updated: 2024/06/05 19:25:52 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	free_command_list(t_command *command_list);
static void	free_pipe(int **pipe, int count);

void	clear_data(t_data *data)
{
	if (!data)
		return ;
	if (data->infile_fd != -1)
	{
		close(data->infile_fd);
		if (data->is_heredoc)
			unlink(TEMP_FILE);
	}
	if (data->outfile_fd != -1)
		close(data->outfile_fd);
	free_strs(data->paths);
	free_command_list(data->command_list);
	free_pipe(data->pipe, data->command_count - 1);
	free(data);
}

static void	free_command_list(t_command *command_list)
{
	t_command	*current;
	t_command	*prev;

	current = command_list;
	while (current)
	{
		free(current->path);
		free_strs(current->argv);
		prev = current;
		current = current->next;
		free(prev);
	}
}

static void	free_pipe(int **pipe, int count)
{
	int	index;

	if (!pipe)
		return ;
	index = 0;
	while (index < count)
	{
		if (!pipe[index])
			break ;
		if (pipe[index][READ_END] == -1)
			close(pipe[index][READ_END]);
		if (pipe[index][WRITE_END] == -1)
			close(pipe[index][WRITE_END]);
		free(pipe[index]);
		index++;
	}
	free(pipe);
}

void	free_strs(char **strs)
{
	int	idx;

	if (!strs)
		return ;
	idx = 0;
	while (strs[idx])
		free(strs[idx++]);
	free(strs);
}
