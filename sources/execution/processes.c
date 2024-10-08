/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:45:22 by vkostand          #+#    #+#             */
/*   Updated: 2024/10/08 20:46:40 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void start_shell(t_data *data, char **argv)
{
    // (void)data;
    (void)argv;
    // cd(data, argv);
    printf("%s\n\n", get_value_from_env(data->env, "PWD"));
    printf("%s\n\n", get_value_from_env(data->env, "OLDPWD"));
    printf("pwd -> %s\n", data->work_dir);
    printf("oldpwd -> %s\n", data->old_work_dir);
    update_workdirs(data, "agsdgsdgsdfg");
    printf("pwd -> %s\n", data->work_dir);
    printf("oldpwd -> %s\n", data->old_work_dir);
    // minishell_error("unset", NULL, "Data error\n");
    // unset(data, argv);
    // print_list(data->env);
    // print_export(data);
    // pwd(data);
    // echo(argv);
}
