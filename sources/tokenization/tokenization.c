/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:31:25 by vkostand          #+#    #+#             */
/*   Updated: 2024/11/22 18:16:07 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include "minishell.h"

int create_tokens(t_data *data)
{
    data->i = 0;
    data->j = 0;
	
    while(data->input[data->i])
    {
        data->quotes_flag = NONE;
        data->j = data->i;
        if(check_pipe_red_env(data))
            continue;
        else if(check_quotes(data))
            continue;
        else if(check_space(data))
            continue;
        while(data->input[data->i] && data->input[data->i] != ' ')
        {
            if(data->input[data->i] == '<' || data->input[data->i] == '>')
                break;
            else if(data->input[data->i] == '$' || data->input[data->i] == '|')
                break;
            else if(data->input[data->i] == '"' || data->input[data->i] == '\'')
                break;
            data->i++;
        }
        data->type = WORD;
        if(fill_tokens(data, data->i, data->j, data->quotes_flag) != EXIT_SUCCESS)
			return(EXIT_FAILURE);
    }
	return(EXIT_SUCCESS);
}

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define RESET_COLOR "\033[0m"
#define BLUE "\033[1;34m"

void print_data(t_data *data)
{
    t_token *pr_token = data->tokens;
    while(pr_token != NULL)
    {

        printf(RED "token --> " RESET_COLOR);
        printf(GREEN "[%s]" RESET_COLOR, pr_token->original_content);
        printf("  (%d) -->", pr_token->quotes);
        printf(YELLOW " type(%d) --> \n" RESET_COLOR, pr_token->type);
        pr_token = pr_token->next;
    }
    printf("⚪️⚪️⚪️⚪️⚪️⚪️⚪️⚪️⚪️⚪️\n");
}

int tokenization(t_data *data)
{
    if(create_tokens(data) != EXIT_SUCCESS)
		return(EXIT_FAILURE);
    if(allot_quotes_value(data) != EXIT_SUCCESS)
		return(EXIT_FAILURE);
    if(tokens_insertion(data) != EXIT_SUCCESS)
		return(EXIT_FAILURE);
	// print_data(data);
	return(EXIT_SUCCESS);
}
// void start_shell(t_data *data)
// {
//     while(1)
//     {
//         data->input = readline(BLUE "Verishen: " RESET_COLOR);
//         if (data->input)
//             add_history(data->input);
//         // print_data(data);
//         tokenization(data);
//         printf("✅ CORRECT INPUT\n");
//         free_tokens(data);
//         //("leaks minishell");
//     }
// }
