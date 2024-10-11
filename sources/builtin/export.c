/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:32:07 by vkostand          #+#    #+#             */
/*   Updated: 2024/10/11 19:51:18 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_export(struct t_env_export *export)
{
    struct t_env_export *temp;

    temp = merge(export, ft_strcmp);
    while(temp)
    {
        if(temp->key)
            printf("declare -x %s", temp->key);
        if(temp->value)
            printf("=\"%s\"\n", temp->value);
        else
            printf("\n");
        temp = temp->next;
    }
    free_env_export(export);
    export = NULL;
}

struct t_env_export *add_oldpwd(t_data *data)
{
    struct t_env_export *oldpwd;
    struct t_env_export *temp;
    
    temp = data->export;
    while(temp && ft_strcmp(temp->key, "OLDPWD") != 0)
        temp = temp->next;
    if(!temp)
    {
        oldpwd = (struct t_env_export *)malloc(sizeof(struct t_env_export));
        if(!oldpwd)
            exit_shell(data, MALLOC_ERR);
        oldpwd->key = ft_strdup("OLDPWD");
        oldpwd->next = data->export;
        return (oldpwd);
    }
    else
        return (data->export);
}

int export(struct t_env_export *export, char **args)
{
    int i;
    
    if(!export || !args)
        return(EXIT_FAILURE);
    if(args[0] && !args[1])
        return (print_export(export), EXIT_SUCCESS);
    i = 1;
    while(args[i])
    {
        if(check_variable_name(args[i]) == EXIT_SUCCESS)
        {
            if(update_env(export, find_key(args[i]), find_value(args[i])) != EXIT_SUCCESS)
                return (EXIT_FAILURE);
        }
        else
            minishell_error("export", args[i], "not a valid identifier");
        i++;
    }
    return (EXIT_SUCCESS);
}


// int update_export(struct t_env_export *export, char *key, char *value)
// {
    
// }

// void add_oldpwd(t_data *data)
// {
//     struct t_env_export *oldpwd;
//     struct t_env_export *temp;
    
//     oldpwd = (struct t_env_export *)malloc(sizeof(struct t_env_export));
//     if(!oldpwd)
//         exit_shell(data, MALLOC_ERR);
//     oldpwd->key = ft_strdup("OLDPWD");
//     printf("aaaaaaaaaa -------->>>> %s\n\n", oldpwd->key);
//     // oldpwd->value = ft_strdup("\0");
//     // printf("bbbbbbbbb -------->>>> %s\n\n", oldpwd->value);

//     temp = data->export;
//     while(temp->next)
//         temp = temp->next;
//     oldpwd->next = NULL;
//     temp->next = oldpwd;
//     printf("bbbbbbbb\n");
//     // free(oldpwd->key);
//     // free(oldpwd->value);
//     // free(oldpwd);
    
// }
