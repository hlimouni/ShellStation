/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_typedefs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:37:34 by iltafah           #+#    #+#             */
/*   Updated: 2021/12/16 08:04:48 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_TYPEDEFS_H
# define PARSER_TYPEDEFS_H

# include "../vectors/vectors.h"
# include "../environment/environment.h"

typedef enum e_tag
{
	e_cmdline_node,
	e_pipeline_node,
	e_simple_cmd_node,
	e_data_node
}	t_tag;

typedef enum e_type
{
	e_start,
	e_pipe,
	e_semicolon,
	e_simple_word,
	less,
	great,
	double_less,
	double_great,
	newline
}	t_type;

/*
** ************************************************************************** **
							redirection linked list
** ************************************************************************** **
*/

typedef struct s_redirection
{
	char					*type;
	char					*file;
	struct s_redirection	*next;
}	t_redirection;

/*
** ************************************************************************** **
						abstruct syntax tree struct
** ************************************************************************** **
*/

typedef struct s_dir
{
	struct s_ast	*next;
	struct s_ast	*bottom;
}	t_dir;

typedef struct s_pipe_content
{
	int				pipes_count;
	int				*pids;
	int				og_in;
	int				og_out;
	t_dir	dir;
}	t_pipe_content;

typedef struct s_data_content
{
	t_str_vec		args_vec;
	int				prev_errnum;
	int				in_fd;
	int				out_fd;
	t_redirection	*redirections;
}	t_data_content;

typedef struct s_ast
{
	t_tag	tag;
	union u_node
	{
		t_dir			dir;
		t_data_content	data;
		t_pipe_content	pipe;
	}	node;
}	t_ast;

/*
** ************************************************************************** **
						tokens linked list struct
** ************************************************************************** **
*/

typedef struct s_tokens
{
	char			*data;
	t_type			type;
	struct s_tokens	*next;
}	t_tokens;

/*
** ************************************************************************** **
*/

#endif
