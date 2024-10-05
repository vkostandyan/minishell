/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:32:52 by vkostand          #+#    #+#             */
/*   Updated: 2024/10/03 17:19:55 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void pwd(t_data *data)
{
    char pwd[PATH_MAX];

    if(!getcwd(pwd, PATH_MAX))
    {
        printf("minishell: can't read getcwd\n");
        exit_shell(data, 1);
    }
    write(STDOUT_FILENO, pwd, ft_strlen(pwd));
	write(STDOUT_FILENO, "\n", 1);
}
