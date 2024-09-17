/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:31:25 by vkostand          #+#    #+#             */
/*   Updated: 2024/09/17 18:43:49 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int make_tokens(t_data *data)
// {
//     int count;
//     int i;
    
//     i = 0;
//     count = 0;
//     while(data->input[i])
//     {
//         if(data->input[i] && (data->input[i] == '"' || data->input[i] == '\''))
//         {
//             i++;
//             while (data->input[i] && !(data->input[i] == '"'))
//                 i++;
//             while(data->input[i] && !(data->input[i] == '\''))
//                 i++;
//             if(!data->input[i])
//                 exit(1);
//             i++;
//             count++;
//         }
//         else if(data->input[i] == ' ' || data->input[i] == '\t')
//         {
//             count++;
//             while(data->input[i] && (data->input[i] == ' ' || data->input[i] == '\t'))
//                 i++;
//         }
//         i++;
//     }
//     return(0);
// }

void create_tokens(t_data *data)
{
    (void)data;
}

void start_shell(t_data *data)
{
    while(1)
    {
        data->input = readline("Verishen: ");
        create_tokens(data); 
        printf("--> %s\n", data->input);
    }
}