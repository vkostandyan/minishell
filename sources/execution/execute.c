/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:34:29 by vkostand          #+#    #+#             */
/*   Updated: 2024/11/13 23:07:02 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dups(t_data *data __attribute__((unused)))
{
    printf("loll\n");
	// if (data->pipe_index != 0 && dup2(data->fd[data->pipe_index
	// 		- 1][0], 0) == -1)
	// {
	// 	// close_pipes(data);
	// 	minishell_error("pipe error", "", "");
	// 	exit(1);
	// }
    // printf("data->pipe_index -> %d\n", data->pipe_index);
    // printf("data->pipe_count -> %d\n", data->pipe_count);

	// if (data->pipe_index < data->pipe_count
	// 	&& dup2(data->fd[data->pipe_index][1], 1) == -1)
	// {
    //     printf("bbb\n");
    //     // close_pipes(data);
	// 	minishell_error("pipe error", "", "");
	// 	exit(1);
	// }
	// close_pipes(data);
}

int	run_cmd(t_data *data)
{
	int		pid;
	char	*path;
	char	**path_args;

	pid = fork();
	if (pid == -1)
	{
		minishell_error("fork failed", "", "");
		set_g_exit_status(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (is_builtin(data->commands->name))
		{
            run_builtin(data, data->commands->args);
			// exit(0);
		}
		path_args = ft_split(get_value_from_env(data->env, "PATH"), ':');
		path = get_command_path(path_args, data->commands->args[0]);
		free_array(path_args);
		execve(path, data->commands->args, list_to_array(data->env));
		minishell_error("Executing command failed", "", "");
		// exit(1);
	}
	return (EXIT_SUCCESS);
}
int	run_commands(t_data *data)
{
	// if (data->pipe_count == 0)
	// {
	//     if(data->commands->args[0] && is_builtin(data->commands->name))
	//         run_builtin(data, data->commands->args);
	// }
	run_cmd(data);
    return (EXIT_SUCCESS);
}

int	execute(t_data *data)
{
	while (data->pipe_index < data->pipe_count)
	{
        printf("aa\n");
		dups(data); 
		run_commands(data);
		// free one command
		data->pipe_index++;
	}
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

