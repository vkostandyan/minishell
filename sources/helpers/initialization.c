/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:57:05 by vkostand          #+#    #+#             */
/*   Updated: 2024/10/03 19:29:15 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void init_data(t_data *data, char **env)
{
    data->env = init_env(env);
    data->export = init_env(env);
    clarify_shlvl(data->env);
    clarify_shlvl(data->export);
    data->export = add_oldpwd(data);
    data->export = merge(data->export, ft_strcmp);
}