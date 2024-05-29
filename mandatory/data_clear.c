/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:21:01 by rolee             #+#    #+#             */
/*   Updated: 2024/05/29 20:26:05 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_strs(char **strs);

void clear_data(t_data *data)
{
	if (!data)
		return ;
	if (data->infile_fd != -1)
		close(data->infile_fd);
	if (data->outfile_fd != -1)
		close(data->outfile_fd);
	free_strs(data->paths);
	if (data->cmd1)
	{
		free(data->cmd1->path);
		free_strs(data->cmd1->argv);
		free(data->cmd1);
	}
	if (data->cmd2)
	{
		free(data->cmd2->path);
		free_strs(data->cmd2->argv);
		free(data->cmd2);
	}
}

static void	free_strs(char **strs)
{
	int	idx;

	if (!strs)
		return ;
	idx = 0;
	while (strs[idx])
		free(strs[idx++]);
	free(strs);
}
