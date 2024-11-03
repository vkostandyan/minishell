/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:45:22 by vkostand          #+#    #+#             */
/*   Updated: 2024/11/03 18:25:04 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
////// khanes sa /////
#define BLUE "\033[1;34m"
# define RESET_COLOR "\033[0m"

int count_list_len(t_data *data)
{
    int len;

    len = 0;
    data->current = data->tokens;
    while(data->current)
    {
        len++;
        data->current = data->current->next;
    }
    return (len);
}

char **tokens_to_matrix(t_data *data)
{
    char **matrix;
    int i;
    int len;

    len = count_list_len(data);
    data->current = data->tokens;
    matrix = (char **)malloc(sizeof(char *) * (len + 1));
    if(!matrix)
        return (NULL);
    i = 0;
    while (data->current)
    {
        matrix[i] = ft_strdup(data->current->original_content);
        printf("matrix[i] -> %s\n", matrix[i]);
        // matrix[i] = (char *)malloc(sizeof(char) * ft_strlen(data->current->original_content));
        if(!matrix[i])
            return (free_array(matrix), NULL);
        i++;
        data->current = data->current->next;
    }
    matrix[i] = NULL;
    return (matrix);
}

void start_shell(t_data *data)
{   
    char **matrix;

    while(1)
    {
        data->input = readline(BLUE "Verishen: " RESET_COLOR);
        if (data->input)
            add_history(data->input);
        tokenization(data);
        print_data(data);
        printf("len -> %d\n\n", count_list_len(data));
        matrix = tokens_to_matrix(data);
        free_array(matrix);
        // printf("✅ CORRECT INPUT\n");
        free_tokens(data);
        system("leaks minishell");
    }
}
