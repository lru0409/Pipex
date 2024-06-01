/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:14:11 by rolee             #+#    #+#             */
/*   Updated: 2024/05/30 21:45:03 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

# define WRITE_END 1
# define READ_END 0

# define TRUE 1
# define FALSE 0

# define HEREDOC "here_doc"
# define TEMP_FILE "tempfile"

# define CHILD 0
# define PARENT 1

typedef struct s_command
{
	char					*path;
	char					**argv;
	struct s_command		*next;
}	t_command;

typedef struct s_data
{
	int			infile_fd;
	int			outfile_fd;
	int			is_heredoc;
	char		**paths;
	int			command_count;
	// TODO
	t_command	*command_list;
	int			**pipe;
}	t_data;

// manage_heredoc
int			manage_heredoc(char *argv[], t_data *data);

// data_setup
int			set_data(int argc, char *argv[], char *env[], t_data *data);
t_command	*set_command(char *cmd_argv, char *paths[]);
void		add_command(t_command **command_list, t_command *new);

// data_clear
void		clear_data(t_data *data);
void		free_strs(char **strs);

// execute
void 		execute_commands(t_data *data, char *env[]);
int 		wait_processes(t_data *data);

#endif