/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:23:49 by rolee             #+#    #+#             */
/*   Updated: 2024/05/24 13:24:42 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
	t_command	*cmd1;
	t_command	*cmd2;
	int			pipe[2];
}	t_data;

// data_setup
t_data	*create_data();
int		set_data(char *argv[], char *env[], t_data *data);

// data_clear
void clear_data(t_data *data);

#endif