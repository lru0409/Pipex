/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_setup_util_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:11:51 by rolee             #+#    #+#             */
/*   Updated: 2024/05/30 21:16:44 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static t_command	*create_command(void);
static char			*get_command_path(char *command, char *paths[]);
static char			*join_path(char *path, char *command);

t_command	*set_command(char *cmd_argv, char *paths[])
{
	t_command	*cmd;

	cmd = create_command();
	if (!cmd)
		return (NULL);
	cmd->argv = ft_split(cmd_argv, ' ');
	if (!cmd->argv) // TODO : cmd->argv[0] = NULL 인 경우가 있나?
		return (NULL);
	if (cmd->argv[0][0] == '/')
		cmd->path = ft_strdup(cmd->argv[0]);
	else
		cmd->path = get_command_path(cmd->argv[0], paths);
	if (!cmd->path) {
		free_strs(cmd->argv);
		free(cmd);
		return (NULL);
	}
	return (cmd);
}

void	add_command(t_command **command_list, t_command *new)
{
	t_command *current;

	if (*command_list == NULL)
	{
		*command_list = new;
		return ;
	}
	current = *command_list;
	while (current->next)
		current = current->next;
	current->next = new;
}

static t_command	*create_command(void)
{
	t_command	*cmd;

	cmd = (t_command *)malloc(sizeof(t_command));
	if (!cmd)
		return (NULL);
	cmd->path = NULL;
	cmd->argv = NULL;
	cmd->next = NULL;
	return (cmd);
}

static char	*get_command_path(char *command, char *paths[])
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

static char	*join_path(char *path, char *command)
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