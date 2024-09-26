/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:57:05 by vkostand          #+#    #+#             */
/*   Updated: 2024/09/26 22:56:03 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void init_data(t_data *data, char **env)
{
    // data->env = ft_arrdup(env);
    // if (!data->env)
    //     exit(1);
    // if(!init_export(data))
    //     exit(1);
    data->env = init_env(env);
    data->export = init_env(env);
    data->export = merge(data->export, ft_strcmp);
    (void)data;
}