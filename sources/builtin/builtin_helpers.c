/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:20:11 by vkostand          #+#    #+#             */
/*   Updated: 2024/10/07 18:24:15 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int check_variable_name(char *name)
{
    if(!name)
        return (EXIT_SUCCESS);
    if(name[0] && !ft_isalpha(name[0]) && name[0] != '_')
        return (EXIT_FAILURE);
    int i;
    i = 1;
    while(name[i])
    {
        if(name[i] != '_' && !ft_isalnum(name[i]))
            return (EXIT_FAILURE);
        i++;
    }
    return (EXIT_SUCCESS);
}
