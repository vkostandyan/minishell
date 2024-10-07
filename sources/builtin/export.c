/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:32:07 by vkostand          #+#    #+#             */
/*   Updated: 2024/10/07 19:01:30 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

struct t_env_export *add_oldpwd(t_data *data)
{
    struct t_env_export *oldpwd;
    struct t_env_export *temp;
    
    temp = data->export;
    while(temp && ft_strcmp(temp->value, "OLDPWD") != 0)
        temp = temp->next;
    if(temp)
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
