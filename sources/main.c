/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:38:59 by vkostand          #+#    #+#             */
/*   Updated: 2024/10/05 17:25:24 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **env)
{
    t_data *data;

    data = malloc(sizeof(data));
    if(!data)
        exit(3);
    init_data(data, env);
    echo();
    // print_export(data);
    // pwd(data);
    clean_data(data);
    system("leaks minishell");
    (void)argc;
    (void)argv;
    return (0);
}