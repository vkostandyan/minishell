/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 16:27:50 by vkostand          #+#    #+#             */
/*   Updated: 2024/11/05 19:38:33 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

#define FORK_ERR "fork: Resource temporarily unavailable"

void start_shell(t_data *data);
int lexer(t_data *data);

#endif
