/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 20:07:05 by vkostand          #+#    #+#             */
/*   Updated: 2024/09/20 12:49:30 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print_array(char **str)
{
	int i;
	
	i = 0;
    while (str[i])
    {
        printf("%s\n", str[i]);
        i++;
    }
}

void	*free_array(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str[i]);
	str[i] = NULL;
	free(str);
	str = NULL;
	return (NULL);
}

int count_array_len(char **str)
{
	int i;

	i = 0;
	if(!str)
		return (i);
	while(str[i])
		i++;
	printf("len -> %d\n", i);
	
	return (i);
}