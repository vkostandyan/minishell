/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:36:18 by vkostand          #+#    #+#             */
/*   Updated: 2024/11/12 17:37:24 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int builtin_exit(t_data *data)
{
    write(STDOUT_FILENO, "exit\n", 5);
	if (!data)
	{
		minishell_error("exit", "NULL", "Data error\n");
		return (EXIT_FAILURE);
	}
}
