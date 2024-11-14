/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:45:22 by vkostand          #+#    #+#             */
/*   Updated: 2024/11/14 22:17:03 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define BLUE "\033[1;34m"
# define RESET_COLOR "\033[0m"

void start_shell(t_data *data)
{
    // int status;
    
    while(1)
    {
        data->input = readline(BLUE "Verishen: " RESET_COLOR);
        if (data->input)
            add_history(data->input);
        tokenization(data);
        // create_commands(data);
        //if(!data->input) ...
        // status = lexer(data);
        if(get_g_exit_status() == EXIT_SUCCESS)
        {
			create_commands(data); 
            data->pid = malloc(sizeof(int) * (data->pipe_count + 1));
            // if(!)
            data->index = 0;
            data->pipe_index = 0;
            create_pipes(data);
            set_g_exit_status(execute(data));
            close_pipes(data);
            
        }
        free_commands(data);
        free_tokens(data);
        // system("leaks minishell");
    }
}
