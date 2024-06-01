/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lru0409 <lru0409@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 16:05:01 by lru0409           #+#    #+#             */
/*   Updated: 2024/06/01 16:32:57 by lru0409          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void    close_pipe(int process, int count, t_data *data);
static void    set_redirection(int count, t_data *data);

void execute_commands(t_data *data, char *env[])
{
    t_command   *cmd;
    int         count;
    int         pid;

    cmd = data->command_list;
    count = 0;
    while (count < data->command_count)
    {
        pid = fork();
        if (pid == 0)
        {
            close_pipe(CHILD, count, data);
            set_redirection(count, data);
            if (execve(cmd->path, cmd->argv, env) == -1)
                exit(EXIT_FAILURE);
        }
        close_pipe(PARENT, count, data);
        cmd = cmd->next;
        count++;
    }
}

static void    set_redirection(int count, t_data *data)
{
    if (count == 0)
        dup2(data->infile_fd, STDIN_FILENO);
    else
        dup2(data->pipe[count - 1][READ_END], STDIN_FILENO);
    if (count == data->command_count - 1)
        dup2(data->outfile_fd, STDOUT_FILENO);
    else
        dup2(data->pipe[count][WRITE_END], STDOUT_FILENO);
}

static void    close_pipe(int process, int count, t_data *data)
{
    if (process == CHILD)
    {
        if (count != data->command_count - 1)
            close(data->pipe[count][READ_END]);
    }
    else if (process == PARENT)
    {
        if (count != data->command_count - 1)
            close(data->pipe[count][WRITE_END]);
        if (count != 0)
            close(data->pipe[count - 1][READ_END]);
    }
}

int wait_processes(t_data *data)
{
    int count;
    int wait_pid;
    int status;

    count = 0;
    while (count < data->command_count)
    {
        wait_pid = wait(&status);
        if (wait_pid == -1) // TODO: dup2, wait, pipe .. 어디까지 실패 처리를 해줘야 할까?
        {
            perror("wait");
            return (EXIT_FAILURE);
        }
        count++;
    }
    return (EXIT_SUCCESS);
}
