/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:53:19 by vkostand          #+#    #+#             */
/*   Updated: 2024/09/20 12:33:43 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char *create_export_content(char **env, int i)
// {
//     char *content;

//     content
// }

int count_export_len(t_data *data)
{
    int i;

    i = 0;
    while (data->env[i] && ft_strncmp(data->env[i], "OLDPWD", 6) != 0)
        i++;
    if(data->env[i])
        return (count_array_len(data->env));
    return (count_array_len(data->env) + 1);
}

void init_export(t_data *data)
{
    // int i;

    // data->export = (char **)malloc((char *) * )
    // print_array(data->export);
    // int i = 0;
    // while (data->export[i])
    // {
    //     ft_strjoin("declare -x ", data->export[i]);
    //     i++;
    // }
    // print_array(data->export);
    printf("%d\n", count_export_len(data));
}
