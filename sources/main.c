/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:38:59 by vkostand          #+#    #+#             */
/*   Updated: 2024/11/06 18:01:50 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_exit_status = 0;

void set_g_exit_status(int new_status)
{
    g_exit_status = new_status;
}

int get_g_exit_status()
{
    return (g_exit_status);
}

int main(int argc, char **argv, char **env)
{
    t_data data;
    (void)env;
    // data = malloc(sizeof(data));
    // if(!data)
    //     exit(3);
    init_data(&data, env);
    start_shell(&data);
    clean_data(&data);
    system("leaks minishell");
    (void)argc;
    (void)argv;
    return (0);
}