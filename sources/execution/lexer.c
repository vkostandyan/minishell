/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:41:30 by vkostand          #+#    #+#             */
/*   Updated: 2024/11/06 20:58:08 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
////// khanes sa /////
#define BLUE "\033[1;34m"
# define RESET_COLOR "\033[0m"

char	*ft_join(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	s = (char *)malloc(sizeof(char const) * (ft_strlen(s1) + ft_strlen(s2)
				+ 2));
	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	s[i++] = '/';
	while (s2[j] != '\0')
	{
		s[i + j] = s2[j];
		j++;
	}
	s[i + j] = '\0';
	return (s);
}

char	*get_command_path(char **path_args, char *cmd)
{
	char	*command;

	while (*path_args)
	{
		command = ft_join(*path_args, cmd);
		if (access(command, F_OK) == 0)
			return (command);
		free(command);
		path_args++;
	}
	return (NULL);
}

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
        if(!matrix[i])
            return (free_array(matrix), NULL);
        i++;
        data->current = data->current->next;
    }
    matrix[i] = NULL;
    return (matrix);
}

// t_cmd token_to_command(t_data *data)
// {
//     t_cmd cmd;
// }

// int create_commands(t_data *data)
// {
    
// }

// int lexer(t_data *data)
// {

//     data->input = readline(BLUE "Verishen: " RESET_COLOR);
//     if (data->input)
//         add_history(data->input);
//     tokenization(data);

    
//     int status = 0;
//     int pid;
//     char **args;
//     char **paths;
//     char **env;
//     char *path;
//     // int i = 0;
    

//     pid = fork();
//     if(pid == -1)
//         return (1);    
//     if(pid == 0)
//     {
//         args = tokens_to_matrix(data);
//         paths = ft_split(get_value(data->env, "PATH"), ':');
//         // while(paths[i])
//         // {
//         //     printf("%s\n", paths[i]);
//         //     i++;
//         // }
//         path = get_command_path(paths, args[0]);
//         // printf("path -> %s\n", path);
//         env = list_to_array(data->env);
//         // env list to array
//         execve(path, args, env);
//     }
//     waitpid(pid, NULL, 0);

    
//     free_tokens(data);
//     return (status);
//     // status = create_commands(data);
// }

void run_builtin(t_data *data, char **args)
{
    if(!args || !*args)
        return ;
    if(args[0] && ft_strcmp(args[0], "echo") == 0)
        set_g_exit_status(echo(args));
    if(args[0] && ft_strcmp(args[0], "env") == 0)
        set_g_exit_status(env(data));
    if(args[0] && ft_strcmp(args[0], "pwd") == 0)
        set_g_exit_status(pwd(data));
    if(args[0] && ft_strcmp(args[0], "unset") == 0)
        set_g_exit_status(unset(data, args));
    if(args[0] && ft_strcmp(args[0], "cd") == 0)
        set_g_exit_status(cd(data->env, args));
    if(args[0] && ft_strcmp(args[0], "export") == 0)
    {
        // data->export = export(data->export, args);
        set_g_exit_status(export(data->export, args));
    }
}

int lexer(t_data *data)
{
    char **args;
    
    args = tokens_to_matrix(data);
    if(args[0] && is_builtin(args[0]))
        run_builtin(data, args);
    free_array(args);
    return (0);
}