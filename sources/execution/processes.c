/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:45:22 by vkostand          #+#    #+#             */
/*   Updated: 2024/11/05 21:55:40 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define BLUE "\033[1;34m"
# define RESET_COLOR "\033[0m"

void start_shell(t_data *data)
{   
    int status;
    
    while(1)
    {
        
    //     //if(!data->input) ...
        status = lexer(data);
        system("leaks minishell");
    }
    // char **matrix;

    // while(1)
    // {
    //     data->input = readline(BLUE "Verishen: " RESET_COLOR);
    //     if (data->input)
    //         add_history(data->input);
    //     tokenization(data);
    //     print_data(data);
    //     printf("len -> %d\n\n", count_list_len(data));
    //     matrix = tokens_to_matrix(data);
    //     free_array(matrix);
    //     // printf("✅ CORRECT INPUT\n");
    //     free_tokens(data);
    //     // system("leaks minishell");
    // }
}
