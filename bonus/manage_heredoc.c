/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 21:43:40 by rolee             #+#    #+#             */
/*   Updated: 2024/06/05 19:28:46 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	get_heredoc_input(char *limiter);
static int	is_same(char *line, char *limiter);

int	manage_heredoc(char *argv[], t_data *data)
{
	if (ft_strncmp(argv[1], HEREDOC, ft_strlen(HEREDOC) + 1) != 0)
		return (EXIT_SUCCESS);
	data->is_heredoc = TRUE;
	if (get_heredoc_input(argv[2]) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	get_heredoc_input(char *limiter)
{
	int		tempfile;
	char	*line;

	tempfile = open(TEMP_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (tempfile == -1)
		return (EXIT_FAILURE);
	while (TRUE)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (is_same(line, limiter))
			break ;
		ft_putstr_fd(line, tempfile);
		free(line);
	}
	free(line);
	close(tempfile);
	return (EXIT_SUCCESS);
}

static int	is_same(char *line, char *limiter)
{
	int	limiter_len;

	limiter_len = ft_strlen(limiter);
	if (ft_strncmp(line, limiter, limiter_len) != 0)
		return (FALSE);
	if (line[limiter_len] != '\n')
		return (FALSE);
	return (TRUE);
}
