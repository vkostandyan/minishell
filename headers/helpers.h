/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:51:02 by vkostand          #+#    #+#             */
/*   Updated: 2024/09/26 20:39:46 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

char	**ft_arrdup(char **env);
void    init_data(t_data *data, char **env);
int init_export(t_data *data);
void	*free_array(char **str);
void print_array(char **str);
int count_array_len(char **str);
int count_export_len(t_data *data);
char	*create_export_value(char **env, int i);
void sort_array(char **str);
void print_list(struct t_env_export *env);

//----- Environment -----
char *find_key(char *key_value);
char *find_value(char *key_value);
// void init_env(t_data *data, char **env);
struct t_env_export *init_env(char **env);
struct t_env_export *mid_point(struct t_env_export *head);
struct t_env_export *merge(struct t_env_export *begin, int (*cmp)());

//---- Clean data -----
void clean_data(t_data *data);
void free_env_export(struct t_env_export *env_export);

#endif