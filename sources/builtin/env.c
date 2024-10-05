/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:30:53 by vkostand          #+#    #+#             */
/*   Updated: 2024/09/23 21:29:00 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *find_key(char *key_value)
{
    int i;
    char *key;

    if (!key_value)
        return (NULL);
    i = 0;
    while (key_value[i] && key_value[i] != '=')
        i++;
    key = (char *)malloc(sizeof(char) * (i + 1));
    if (!key)
        return (NULL);
    i = 0;
    while (key_value[i] && key_value[i] != '=')
    {
        key[i] = key_value[i];
        i++;
    }
    key[i] = '\0';
    return (key);
}

char *find_value(char *key_value)
{
    int i;
    int j;
    char *value;

    if (!key_value)
        return (NULL);
    i = ft_strlen(key_value) - 1;
    while (i >= 0 && key_value[i] != '=')
        i--;
    value = (char *)malloc(sizeof(char) * (ft_strlen(key_value) - i));
    if (!value)
        return (NULL);
    i++;
    j = 0;
    while (key_value[i])
    {
        value[j++] = key_value[i];
        i++;
    }
    value[j] = '\0';
    return (value);
}

struct t_env_export *init_env(char **env)
{
    int i;
    struct t_env_export *new_env;
    struct t_env_export temp;

    new_env = &temp;
    i = 0;
    while(env[i])
    {
        new_env->next = malloc(sizeof(struct t_env_export));
        if(!new_env)
            exit(2);
        new_env->next->key = find_key(env[i]);
        new_env->next->value = find_value(env[i]);
        new_env->next->next = NULL;
        new_env = new_env->next;
        i++;
    }
    new_env = temp.next;
    return(new_env);
}

// void init_env(t_data *data, char **env)
// {
//     struct t_env_export temp;       
//     int i;

//     i = 0;
//     data->env = &temp;
//     while (env[i])
//     {
//         data->env = malloc(sizeof(struct t_env_export));
//         if(!data->env)
//             exit (2);
//         data->env->key = find_key(env[i]);
//         data->env->value = find_value(env[i]);
//         // printf("key-> %s\n", data->env->key);
//         // printf("value-> %s\n", data->env->value);
//         // printf("aaa\n");
//         // data->env->next->next = NULL;
//         data->env = data->env->next;
//         i++;
//     }
//     // data->env->next = NULL;
// }
