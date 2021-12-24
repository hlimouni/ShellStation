/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_typedefs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:37:34 by iltafah           #+#    #+#             */
/*   Updated: 2021/12/24 14:59:09 by hlimouni         ###   ########.fr       */
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

/*
** * t_pipe_content holds data of the cureent pipeline *
**		sequence defined as:
**
** * pipes_count: the number of pipes in the pipline_seq
** * pids: the array which holds the pids of every forked process
** * og_in: dupped fd of the original standard input stream
** * out_fd: dupped fd of the original standard output stream 
*/

typedef struct s_pipe_content
{
	int				pipes_count;
	int				*pids;
	int				og_in;
	int				og_out;
	t_dir			dir;
}	t_pipe_content;

/*
** * the structure t_data_contents holds data of the *
** 		current simple command defined as:
**
** * args_vec: the vector which holds the arguments of the command.
** * prev_errnum: holds the previous command error number.
** * in_fd: holds the fd of the input stream of the command.
** * out_fd: holds the fd of the output stream of the command.
*/

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
