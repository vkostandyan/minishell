/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:23:21 by vkostand          #+#    #+#             */
/*   Updated: 2024/10/08 20:41:43 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// cd -
// cd ..
// cd path
// cd 

// int cd(t_data *data, char **args) // int cd(t_data *data)
// {
//     int	status;

// 	if (!data)
// 	{
// 		minishell_error("cd", "NULL", "Data error\n");
// 		return (EXIT_FAILURE);
// 	}
//     if(args[1]) // data->commands->args[1]
//         status = change_directory(data, NULL);
//     else
//         status = change_directory(data, args[1]); //data->commands->args[1]
//     if(status != EXIT_SUCCESS)
//         return (status);
//     status = update_environement(data);
//     return (status);
// }
