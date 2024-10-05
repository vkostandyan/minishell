/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 20:38:25 by vkostand          #+#    #+#             */
/*   Updated: 2024/10/05 17:27:10 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int has_option(char *str)
{
    int i;

    i = 0;
    if(str[i] != '-')
        return (0);
    i++;
    while (str[i])
    {
        if (str[i] == '-')
			return (0);
		else if (str[i] != 'n')
			return (0);
        i++;
    }
    return(1);
}

int echo()
{
    printf("option -> %d\n", has_option("-n -n"));
    return (0);
}

// int echo(char **args)
// {
    
// }
