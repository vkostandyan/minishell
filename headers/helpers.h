/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:51:02 by vkostand          #+#    #+#             */
/*   Updated: 2024/10/03 17:20:45 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# define MALLOC_ERR 3
# define CWD_ERR 4
# define PATH_MAX 1024

char				**ft_arrdup(char **env);
void				init_data(t_data *data, char **env);
int					init_export(t_data *data);
void				*free_array(char **str);
void				print_array(char **str);
int					count_array_len(char **str);
void				sort_array(char **str);
void				print_list(struct t_env_export *env);

//---- Clean data -----
void				clean_data(t_data *data);
void				exit_shell(t_data *data, int exit_signal);

#endif