/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:31:25 by vkostand          #+#    #+#             */
/*   Updated: 2024/11/11 20:19:05 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void free_tokens(t_data *data)
{
    t_token *current = data->tokens;
    t_token *next;

    while (current != NULL) 
    {
        next = current->next;
        if (current->original_content)
        {
            free(current->original_content);
            current->original_content = NULL;
        }
        free(current);
        current = next;
    }
    data->tokens = NULL;
    free(data->input);
    data->input = NULL;
}

int fill_tokens(t_data *data, int i, int j, int quotes)
{
    t_token *token1;
    
    if(i - j <= 0)
        return(EXIT_FAILURE);
    token1 = ft_lstnew(quotes);
    if(!token1)
        return(MALLOC_ERR);
    token1->original_content = ft_strndup(data->input, i, j);
    token1->type = data->type;
    if (!token1->original_content)
    {
        free(token1);
        return(MALLOC_ERR);
    }
    ft_lstadd_back(&data->tokens, token1);
    return(EXIT_SUCCESS);
}

int check_pipe_red_env(t_data *data)
{
    if(data->input[data->i] == '|')
    {
        data->i++;
        data->type = PIPE;
        set_g_exit_status(fill_tokens(data, data->i, data->j, data->quotes_flag));
        // fill_tokens(data, data->i, data->j, data->quotes_flag);
        return(1);
    }
    else if(data->input[data->i] == '>' || data->input[data->i] == '<')
    {
        data->i++;
        data->type = REDIR;
        set_g_exit_status(fill_tokens(data, data->i, data->j, data->quotes_flag));
        // fill_tokens(data, data->i, data->j, data->quotes_flag);
        return(1);
    }
    else if(data->input[data->i] == '$')
    {
        data->i++;
        data->type = WORD;
        set_g_exit_status(fill_tokens(data, data->i, data->j, data->quotes_flag));
        // fill_tokens(data, data->i, data->j, data->quotes_flag);
        return(1);
    }
    return(0);
}

int check_quotes(t_data *data)
{
    if(data->input[data->i] == '"')
    {
        data->i++;
        data->quotes_flag = DOUBLE;
        data->type = WORD;
        set_g_exit_status(fill_tokens(data, data->i, data->j, data->quotes_flag));
        // fill_tokens(data, data->i, data->j, data->quotes_flag);
        return(1);
    }
    else if(data->input[data->i] == '\'')
    {
        data->i++;
        data->quotes_flag = SINGLE;
        data->type = WORD;
        set_g_exit_status(fill_tokens(data, data->i, data->j, data->quotes_flag));
        // fill_tokens(data, data->i, data->j, data->quotes_flag);
        return(1);
    }
    return(0);
}

int check_space(t_data *data)
{
    while(data->input[data->i] && data->input[data->i] == ' ')
        data->i++;
    // if(data->input[data->j] == ' ' && data->quotes_flag == 0)
    // {
    //     data->j = data->i - 1;
    //     data->type = SPACE;
    //     fill_tokens(data, data->i, data->j, data->quotes_flag);
    //     return(1);
    // }
    if(data->input[data->j] == ' ')// && data->quotes_flag != 0)
    {
        data->type = SPACE;
        set_g_exit_status(fill_tokens(data, data->i, data->j, data->quotes_flag));
        // fill_tokens(data, data->i, data->j, data->quotes_flag);
        return(1);
    }
    return(0);
}
