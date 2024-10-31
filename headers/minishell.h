/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:25:48 by vkostand          #+#    #+#             */
/*   Updated: 2024/10/31 17:01:23 by vkostand         ###   ########.fr       */
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


typedef struct s_env_export t_env_export;

typedef struct s_token t_token;

typedef struct s_data t_data;


struct s_data
{
    // Vitali
    struct t_env_export *export;
    struct t_env_export *env;
    

    // Karen
    int i;
    int j;
    int quotes_flag;
    int type;
    t_token *tokens;
    t_token *current;
    char *input;
};

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
#include "tokenization.h"

// void tokenization(t_data *data);
// void start_shell(t_data *data);
// void	ft_lstadd_back(t_token **lst, t_token *new);
// t_token	*ft_lstnew(void *content);

#endif