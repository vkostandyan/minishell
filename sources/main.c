/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:38:59 by vkostand          #+#    #+#             */
/*   Updated: 2024/10/07 13:00:38 by vkostand         ###   ########.fr       */
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
    start_shell(data, argv + 1);
    clean_data(data);
    system("leaks minishell");
    (void)argc;
    (void)argv;
    return (0);
}