/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:23:49 by rolee             #+#    #+#             */
/*   Updated: 2024/05/29 20:11:23 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h> // TODO : 안 쓰면 지우기

# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define WRITE_END 1
# define READ_END 0

typedef struct s_command
{
	char	*path;
	char	**argv;
}	t_command;

typedef struct s_data
{
	int			infile_fd;
	int			outfile_fd;
	char		**paths;
	t_command	*cmd1;
	t_command	*cmd2;
	int			pipe[2];
}	t_data;

// data_setup
t_data		*create_data();
int			set_data(char *argv[], char *env[], t_data *data);
t_command	*create_command();
char		*get_command_path(char *command, char *paths[]);

// data_clear
void 		clear_data(t_data *data);

// execute
void	execute_first_command(t_data *data, char *env[]);
void	execute_second_command(t_data *data, char *env[]);
int		wait_processes();

#endif