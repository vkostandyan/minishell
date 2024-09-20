/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:51:02 by vkostand          #+#    #+#             */
/*   Updated: 2024/09/20 12:16:52 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H


char	**ft_arrdup(char **env);
void    init_data(t_data *data, char **env);
void init_export(t_data *data);
void	*free_array(char **str);
void print_array(char **str);
int count_array_len(char **str);


#endif