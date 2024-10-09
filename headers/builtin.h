/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:17:10 by vkostand          #+#    #+#             */
/*   Updated: 2024/10/09 21:30:33 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# define PATH_MAX 1024

/*
	cd functions
*/
int cd(struct t_env_export *env, char **args);
int update_workdirs(t_data *data, char *new_path);

/*
	echo functions
*/
int					has_option(char *str);
int					echo(char **args);

/*
	env functions
*/
struct t_env_export	*init_env(char **env);
void				clarify_shlvl(struct t_env_export *env_export);
char				*get_value_from_env(struct t_env_export *env, char *key);
int update_env(struct t_env_export *env, char *key, char *value);

/*
	export functions
*/
int					count_export_len(t_data *data);
char				*create_export_value(char **env, int i);
void				print_export(t_data *data);
struct t_env_export	*add_oldpwd(t_data *data);
struct t_env_export	*mid_point(struct t_env_export *head);
struct t_env_export	*merge(struct t_env_export *begin, int (*cmp)());

/*
	pwd functions
*/
int					pwd(t_data *data);

/*
	unset functions
*/
int					unset(t_data *data, char **args); // int unset(t_data *data)

/*
	builtin helper functions
*/
int					check_variable_name(char *name);

#endif