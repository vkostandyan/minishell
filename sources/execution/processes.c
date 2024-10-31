/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:45:22 by vkostand          #+#    #+#             */
/*   Updated: 2024/10/31 18:25:05 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
////// khanes sa /////
#define BLUE "\033[1;34m"
# define RESET_COLOR "\033[0m"

void start_shell(t_data *data)
{   
    while(1)
    {
        data->input = readline(BLUE "Verishen: " RESET_COLOR);
        if (data->input)
            add_history(data->input);
        print_data(data);
        tokenization(data);
        printf("✅ CORRECT INPUT\n");
        free_tokens(data);
        //("leaks minishell");
    }
}
