/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:25:48 by vkostand          #+#    #+#             */
/*   Updated: 2024/10/30 17:27:05 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdio.h>
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "tokenization.h"

typedef struct s_env_export t_env_export;

typedef struct s_data
{
    struct t_env_export *export;
    struct t_env_export *env;
    
    t_token *tokens;
    char *input;
}               t_data;

struct t_env_export
{
    char *key;
    char *value;
    struct t_env_export *next;  
};

#include "libft.h"
#include "helpers.h"
#include "builtin.h"
#include "execution.h"

// void start_shell(t_data *data);
// void	ft_lstadd_back(t_token **lst, t_token *new);
// t_token	*ft_lstnew(void *content);

#endif