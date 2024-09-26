/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:38:59 by vkostand          #+#    #+#             */
/*   Updated: 2024/09/26 20:42:54 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **env)
{
    t_data *data;
    
    // init_data(&data, env);
    // count_array_len(data.env);
    // printf("%s\n",data.export[0]);
    // print_array(data.export);
    // start_shell(&data);
    // free_array(data.env);
    // free_array(data.export);
    // char *key = find_key("aaaaaaaaa=bbbbb");
    // printf("%s\n", key);
    // free(key);
    data = malloc(sizeof(data));
    if(!data)
        exit(3);
    init_data(data, env);
    // struct t_env_export *test = mid_point(data->env);
    
    print_list(data->export);
    // printf("value %s\n", data->env->value);
    clean_data(data);
    data->export = NULL;
    // while (data.env != NULL)
    // {
    //     printf("key-> %s\n", data.env->key);
    //     printf("value-> %s\n", data.env->value);
    //     data.env = data.env->next;
    // }
    system("leaks minishell");
    (void)argc;
    (void)argv;
    (void)env;
    return (0);
}