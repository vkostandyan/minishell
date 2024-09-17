/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkostand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:25:29 by vkostand          #+#    #+#             */
/*   Updated: 2024/09/16 18:32:12 by vkostand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZATION_H
# define TOKENIZATION_H

typedef enum s_quotes t_quotes;
typedef enum s_type t_type;
typedef struct s_token t_token;

enum s_quotes
{
    NONE,
    SINGLE,
    DOUBLE,
};

enum s_type
{
    PIPE,
    REDIR,
    HEREDOC,
    ENV,
    WORD,
    SPACE,
};

struct s_token
{
    t_token *next;
    t_token *prev;
    t_type type;
    t_quotes quotes;
    char *content;
    char *original_content;
};

// void start_shell(t_data *data);

#endif