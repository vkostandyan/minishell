/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:34:29 by vkostand          #+#    #+#             */
/*   Updated: 2024/11/14 20:02:07 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dups(t_data *data)
{
	// (void)data;
	if (data->pipe_index != 0 && dup2(data->fd[data->pipe_index - 1][0], 0) == -1)
	{
		close_pipes(data);
		minishell_error("pipe error", "", "");
		exit(1);
	}
	if (data->pipe_index < data->pipe_count
		&& dup2(data->fd[data->pipe_index][1], 1) == -1)
	{
		close_pipes(data);
		// close(data->fd[0][0]);
		minishell_error("pipe error", "", "");
		exit(1);
	}
	write(2, "blabla\n", 7);
	close_pipes(data);
}



// void	dupeing(t_pipex *pipex, t_cmd *cmd)
// {
// 	if (cmd->input != 0)
// 	{
// 		if (dup2(cmd->input, 0) == -1)
// 			p_error(pipex, DUP_ERR, NULL, 1);
// 		close(cmd->input);
// 	}
// 	if (cmd->output != 1)
// 	{
// 		if (dup2(cmd->output, 1) == -1)
// 			p_error(pipex, DUP_ERR, NULL, 1);
// 		close(cmd->output);
// 	}
// 	close_pipes(pipex);
// }

int	run_cmd(t_data *data)
{
	// int		pid;
	char	*path;
	char	**path_args;

	if (is_builtin(data->commands->name))
	{
		printf("1\n");
		run_builtin(data, data->commands->args);
		return (0);
	}
	data->pid[data->index] = fork();
	if (data->pid[data->index] == -1)
	{
		minishell_error("fork failed", "", "");
		set_g_exit_status(EXIT_FAILURE);
	}
	if (data->pid[data->index] == 0)
	{
		dups(data);
		path_args = ft_split(get_value_from_env(data->env, "PATH"), ':');
		path = get_command_path(path_args, data->commands->args[0]);
		free_array(path_args);
		
		printf("AGVANNNNN ___ %s \n", path);
		execve(path, data->commands->args, list_to_array(data->env));
		minishell_error("Executing command failed", "", "");
		exit(1);
	}
	data->index++;
	// waitpid(pid, NULL, 0);
	return (EXIT_SUCCESS);
}
// int	run_commands(t_data *data)
// {
// 	if (data->pipe_count == 0)
// 	{
// 	    if(data->commands->args[0] && is_builtin(data->commands->name))
// 	        run_builtin(data, data->commands->args);
// 	}
// 	run_cmd(data);
// 	return (EXIT_SUCCESS);
// }

int	execute(t_data *data)
{
	printf("%d %d\n", data->pipe_count, data->pipe_index);
	while (data->pipe_index <= data->pipe_count)
	{
	printf("%d %d\n", data->pipe_count, data->pipe_index);
		// dups(data);
		int i = 0;
		while (data->commands->args[i])
		{
			printf("data->commands->args[i] -> %s\n", data->commands->args[i]);
			i++;
		}
		run_cmd(data);
		data->commands = data->commands->next;
		// free one command
		data->pipe_index++;
	}
	close_pipes(data);
	// if (data->pipe_index == 0)
	// 	run_cmd(data);
	// int a;
	int k = 0;
	while (k < data->index)
	{
		waitpid(data->pid[k], NULL, 0);
		k++;
	}
	write(2, "5\n", 2);
	
	// (void)data;
	// // print_a(data);
	// // char **args;
	// // if (!data->commands)
	// // 	return (0);
	// // args = tokens_to_matrix(data);
	// if(data->commands->args[0] && is_builtin(data->commands->name))
	//     run_builtin(data, data->commands->args);
	// else
	//     run_cmd(data, data->commands->args);
	// // free_array(args);
	return (EXIT_SUCCESS);
}
