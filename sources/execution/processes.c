/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:45:22 by vkostand          #+#    #+#             */
/*   Updated: 2024/10/12 17:24:56 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void start_shell(t_data *data, char **argv)
{
    (void)data;
    (void)argv;
    // printf("res -> %d\n\n", check_variable_name("1"));
    data->export = export(data->export, argv);
    // cd(data->env, argv);
    // minishell_error("unset", NULL, "Data error\n");
    // unset(data, argv);
    // print_list(data->env);
    print_export(data->export);
    // pwd(data);
    // echo(argv);
}
