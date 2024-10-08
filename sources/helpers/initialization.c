/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:57:05 by vkostand          #+#    #+#             */
/*   Updated: 2024/10/08 21:00:17 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_work_dir(t_data *data)
{
	char	buff[PATH_MAX];
	char	*wd;

	wd = getcwd(buff, PATH_MAX);
	data->work_dir = ft_strdup(wd);
	if (!data->work_dir)
		return (0);
	if (get_env_index(data->env, "OLDPWD") != -1)
	{
		data->old_work_dir = ft_strdup(get_env_value(data->env, "OLDPWD"));
		if (!data->old_work_dir)
			return (0);
	}
	else
	{
		data->old_work_dir = ft_strdup(wd);
		if (!data->old_work_dir)
			return (0);
	}
	return (1);
}

void init_data(t_data *data, char **env)
{
    data->work_dir = NULL;
    data->work_dir = NULL;
    data->env = init_env(env);
    data->export = init_env(env);
    clarify_shlvl(data->env);
    clarify_shlvl(data->export);
    data->export = add_oldpwd(data);
    data->export = merge(data->export, ft_strcmp);
    data->work_dir = get_value_from_env(data->env, "PWD");
    data->old_work_dir = get_value_from_env(data->env, "OLDPWD");
    //     data->work_dir = ft_strdup(get_value_from_env(data->env, "PWD"));
    // data->old_work_dir = ft_strdup(get_value_from_env(data->env, "OLDPWD"));
}