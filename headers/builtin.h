/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:17:10 by vkostand          #+#    #+#             */
/*   Updated: 2024/10/05 17:25:16 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# define PATH_MAX 1024

int					count_export_len(t_data *data);
char				*create_export_value(char **env, int i);
void				print_export(t_data *data);
void				clarify_shlvl(struct t_env_export *env_export);
struct t_env_export	*add_oldpwd(t_data *data);
void				pwd(t_data *data);
int echo();

//----- Environment -----
char				*find_key(char *key_value);
char				*find_value(char *key_value);
struct t_env_export	*init_env(char **env);
struct t_env_export	*mid_point(struct t_env_export *head);
struct t_env_export	*merge(struct t_env_export *begin, int (*cmp)());

//---- Clean data -----
void				free_env_export(struct t_env_export *env_export);

#endif