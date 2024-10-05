/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 20:03:31 by vkostand          #+#    #+#             */
/*   Updated: 2024/10/03 19:29:00 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_export(t_data *data)
{
    struct t_env_export *temp;

    temp = data->export;
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
}

void clarify_shlvl(struct t_env_export *env_export)
{
    int shlvl;
    struct t_env_export *temp;
    char *str;
    
    temp = env_export;
    while (temp && ft_strcmp("SHLVL", temp->key) != 0)
    {
        temp = temp->next;
    }
    if(temp)
    {
        shlvl = ft_atoi(temp->value);
        shlvl++;
        free(temp->value);
        str = ft_itoa(shlvl);
        temp->value = ft_strdup(str);
        free(str);
    }
}

void exit_shell(t_data *data, int exit_signal)
{
    clean_data(data);
    exit(exit_signal);
}
