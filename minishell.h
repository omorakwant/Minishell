/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odahriz <odahriz@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:48:17 by odahriz           #+#    #+#             */
/*   Updated: 2025/04/10 13:30:12 by odahriz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIRECT_IN,
	TOKEN_REDIRECT_OUT,
	TOKEN_LOGICAL_OR,
	TOKEN_LOGICAL_AND,
	TOKEN_AND,
	TOKEN_OR,
	TOKEN_WILDCARD,
	TOKEN_EXPANSION_MARK,
	TOKEN_APPEND,
	TOKEN_HEREDOC,
	TOKEN_SYMBOL
}	t_token_type;
 
typedef struct s_token
{
	t_token_type	type;
	char			*value;
	struct s_token	*next;
}	t_token;


typedef struct s_env
{
	char	*key;
	char	*value;
	struct s_env	*next;
}	t_env;

typedef enum e_redirection_type
{
	REDIRECT_IN,
	REDIRECT_OUT,
	REDIRECT_APPEND,
	HEREDOC
}	t_redirection_type;

typedef struct s_redirection
{
	t_redirection_type	type;
	char	*file;
	int 	fd;
}	t_redirection;

typedef struct s_cmd
{
	char	**args;
	int		arg_count;
	t_redirection	*redirections;
	int	redirection_count;
}	t_cmd;

typedef struct s_ast
{
	t_token_type	type;
	char			*value;
	t_cmd			*cmd;
	struct s_ast	*left;
	struct s_ast	*right;
}	t_ast;

int checksyntax(char *line);

#endif