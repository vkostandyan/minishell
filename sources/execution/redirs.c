/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:18:20 by vkostand          #+#    #+#             */
/*   Updated: 2024/12/05 21:01:38 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *get_error_message(t_data *data)
{
	char *tmp;
	char *result;

	tmp = NULL;
	result = NULL;
	tmp = ft_strjoin(data->current->original_content, ": ");
	if(!tmp)
		return (NULL);
	result = ft_strjoin(tmp, strerror(errno));
	free(tmp);
	return (result);
}

int	open_file_and_remove_token_2(t_data *data)
{
	if (ft_strcmp(data->current->original_content, "<<") == 0)
	{
		data->current = ft_lst_delone(&data->tokens, data->current);
		data->curr_cmd->stdin = open_heredoc(data, data->current->original_content, data->current->quotes);
		if (data->curr_cmd->stdin == -1)
		{
			// join
			// data->curr_cmd->error = ft_strdup(strerror(errno));
			data->curr_cmd->error = get_error_message(data);
			if (!data->curr_cmd->error)
			{
				return (MALLOC_ERR);
				//malloc_error
			}
			return (EXIT_FAILURE);
		}
	}
	else
	{
		data->current = ft_lst_delone(&data->tokens, data->current);
		data->curr_cmd->stdin = open_infile(data->current->original_content);
		if (data->curr_cmd->stdin == -1)
		{
			data->curr_cmd->error = get_error_message(data);
			if (!data->curr_cmd->error)
			{
				return (MALLOC_ERR);
				//malloc_error
			}
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	open_file_and_remove_token(t_data *data)
{
	int	status;

	status = 0;
	if (ft_strcmp(data->current->original_content, ">>") == 0)
	{
		data->current = ft_lst_delone(&data->tokens, data->current);
		data->curr_cmd->stdout = open_outfile(data->current->original_content,
				1);
		if (data->curr_cmd->stdout == -1)
		{
			data->curr_cmd->error = get_error_message(data);
			if (!data->curr_cmd->error)
			{
				return (MALLOC_ERR);
				//malloc_error
			}
			return (EXIT_FAILURE);
		}
	}
	else if (data->current->original_content[0] == '>')
	{
		data->current = ft_lst_delone(&data->tokens, data->current);
		data->curr_cmd->stdout = open_outfile(data->current->original_content,
				0);
		if (data->curr_cmd->stdout == -1)
		{
			data->curr_cmd->error = get_error_message(data);
			if (!data->curr_cmd->error)
			{
				return (MALLOC_ERR);
				//malloc_error
			}
			return (EXIT_FAILURE);
		}
	}
	else
		status = open_file_and_remove_token_2(data);
	data->current = ft_lst_delone(&data->tokens, data->current);
	return (status);
}

// int	check_redir_syntax(t_data *data)
// {
// 	if (data->current->type == REDIR && data->current->next
// 		&& (data->current->next->type == REDIR
// 			|| data->current->next->type == HEREDOC))
// 	{
// 		parse_error(data->current->next->original_content);
// 		set_g_exit_status(258);
// 		return (EXIT_FAILURE);
// 	}
// 	if (data->current->type == REDIR && ((!data->current->next)
// 			|| data->current->next->type == PIPE))
// 	{
// 		parse_error("newline");
// 		set_g_exit_status(258);
// 		return (EXIT_FAILURE);
// 	}
// 	else if ((data->current->type == REDIR || data->current->type == HEREDOC)
// 		&& (data->current->next && data->current->next->type == WORD))
// 	{
// 		if (open_file_and_remove_token(data) && data->pipe_count < 1)
// 			return (EXIT_FAILURE);
// 	}
// 	return (EXIT_SUCCESS);
// }

int	handle_redir_2(t_data *data)
{
	if (data->current && data->current->type == PIPE)
		data->current = data->current->next;
	if (data->current && data->current->next && data->current->type == REDIR
		&& (data->current->next->type == REDIR
			|| data->current->next->type == HEREDOC))
	{
		data->error = parse_error(data->current->next->original_content);
		// if
		// parse_error(data->current->next->original_content);
		return (set_g_exit_status(2), EXIT_FAILURE); // 258
	}
	return (EXIT_SUCCESS);
}

int	handle_redir(t_data *data)
{
	data->current = data->tokens;
	data->curr_cmd = data->commands;
	while (data->current)
	{
		if (handle_redir_2(data) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		if (data->current && data->current->type == REDIR && ((!data->current->next)
				|| data->current->next->type == PIPE))
		{
			data->error = parse_error("newline");
		// if	
			// parse_error("newline");
			return (set_g_exit_status(2), EXIT_FAILURE); // 258
		}
		else if (data->current && (data->current->type == REDIR
				|| data->current->type == HEREDOC) && (data->current->next
				&& data->current->next->type == WORD))
		{
			if (open_file_and_remove_token(data) && data->pipe_count < 1)
				return (EXIT_FAILURE);
		}
		else if (data->current)
			data->current = data->current->next;
		else
			break ;
	}
	return (EXIT_SUCCESS);
}
