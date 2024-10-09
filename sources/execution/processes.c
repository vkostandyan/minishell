/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 19:45:22 by vkostand          #+#    #+#             */
/*   Updated: 2024/10/09 21:30:57 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void start_shell(t_data *data, char **argv)
{
    // (void)data;
    // (void)argv;
    cd(data->env, argv);
    // minishell_error("unset", NULL, "Data error\n");
    // unset(data, argv);
    // print_list(data->env);
    // print_export(data);
    // pwd(data);
    // echo(argv);
}
