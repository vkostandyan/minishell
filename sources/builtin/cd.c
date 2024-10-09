/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:23:21 by vkostand          #+#    #+#             */
/*   Updated: 2024/10/09 22:27:18 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// cd ..
// cd path

// cd 
int cd_home(struct t_env_export *env)
{
    char *cwd;
    char *home;

    cwd = getcwd(NULL, 0);
    home = get_value_from_env(env, "HOME");
    if (!home)
    {
        minishell_error("cd", "", "HOME not set"); 
        free(cwd);
        return (EXIT_FAILURE);
    }
    if(chdir(home) != 0)
    {
        minishell_error("cd", home, "No such file or directory"); 
        free(cwd);
        return (EXIT_FAILURE);
    }
    if(update_env(env, "PWD", home) != EXIT_SUCCESS)
        return (EXIT_FAILURE);
    if(update_env(env, "OLDPWD", cwd) != EXIT_SUCCESS)
        return (EXIT_FAILURE);
    free(cwd);
    return (EXIT_SUCCESS);
}

// cd -
int cd_oldpwd(struct t_env_export *env)
{
    char *pwd;
    char *oldpwd;

    pwd = get_value_from_env(env, "PWD");
    oldpwd = get_value_from_env(env, "OLDPWD");
    if(!oldpwd)
    {
        minishell_error("cd", "", "OLDPWD not set");
        return (EXIT_FAILURE);
    }
    if(chdir(oldpwd) != 0)
    {
        minishell_error("cd", oldpwd, "No such file or directory");
        return(EXIT_FAILURE);
    }
    update_env(env, "PWD", ft_strdup(oldpwd));
    update_env(env, "OLDPWD", ft_strdup(pwd));
    ft_putendl_fd(oldpwd, 1);
    return (EXIT_SUCCESS);
}

int cd(struct t_env_export *env, char **args)
{
    int status;

    (void)args;

    status = cd_home(env);
    printf("status -> %d\n", status);
    printf("pwd -> %s\n", get_value_from_env(env, "PWD"));
    printf("OLDpwd -> %s\n", get_value_from_env(env, "OLDPWD"));
    return (status);
}

// int cd(t_data *data, char **args) // int cd(t_data *data)
// {
//     int	status;

// 	if (!data)
// 	{
// 		minishell_error("cd", "NULL", "Data error\n");
// 		return (EXIT_FAILURE);
// 	}
//     if(args[1]) // data->commands->args[1]
//         status = change_directory(data, NULL);
//     else
//         status = change_directory(data, args[1]); //data->commands->args[1]
//     if(status != EXIT_SUCCESS)
//         return (status);
//     status = update_environement(data);
//     return (status);
// }
