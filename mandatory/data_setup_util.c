/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_setup_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:24:51 by rolee             #+#    #+#             */
/*   Updated: 2024/05/24 14:21:40 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_command	*create_command()
{
	t_command	*cmd;

	cmd = (t_command *)malloc(sizeof(t_command));
	if (!cmd)
		return (NULL);
	cmd->path = NULL;
	cmd->argv = NULL;
	return (cmd);
}

char	*join_path(char *path, char *command)
{
	char	*temp;
	char	*result;

	temp = ft_strjoin(path, "/");
	if (!temp)
		return (NULL);
	result = ft_strjoin(temp, command);
	free(temp);
	if (!result)
		return (NULL);
	return (result);
}

char	*get_command_path(char *command, char *paths[])
{
	int		idx;
	char	*command_path;
	
	idx = 0;
	while (paths[idx])
	{
		command_path = join_path(paths[idx], command);
		if (!command_path)
			return (NULL);
		if (access(command_path, X_OK) == 0)
			return (command_path);
		free(command_path);
		idx++;
	}
	ft_putstr_fd(command, STDERR_FILENO);
	ft_putendl_fd(": command not found", STDERR_FILENO);
	return (NULL);
}
