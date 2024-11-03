/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 16:27:50 by vkostand          #+#    #+#             */
/*   Updated: 2024/11/03 18:24:46 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

typedef struct s_cmd t_cmd;

struct s_cmd
{
    struct s_data *data;
    
    char **args;
    char *path;
};

void start_shell(t_data *data);

#endif
