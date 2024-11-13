/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 16:27:50 by vkostand          #+#    #+#             */
/*   Updated: 2024/11/13 22:10:55 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

#define FORK_ERR "fork: Resource temporarily unavailable"

void start_shell(t_data *data);
int lexer(t_data *data);
int execute(t_data *data);
int create_commands(t_data *data);
void print_a(t_data *data);
void free_commands(t_data *data);

struct s_command
{
	char *name;
	char **args;
    	int stdout;
	int stdin;
	t_command *next;
};

t_command    *ft_lstnew_cmd(void);
void    ft_lstadd_back_cmd(t_command **lst, t_command *new);

int create_pipes(t_data *data);
void	close_pipes(t_data *data);

void run_builtin(t_data *data, char **args);
char	*get_command_path(char **path_args, char *cmd);

#endif
