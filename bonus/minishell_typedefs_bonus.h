/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_typedefs_bonus.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 21:54:28 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:03:56 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TYPEDEFS_BONUS_H
# define MINISHELL_TYPEDEFS_BONUS_H

# include "./readline/readline_bonus.h"

typedef struct s_gvars
{
	t_rdline		rdl_vars;
	t_env_table		env_table;
	int				last_err_num;
}				t_gvars;

typedef struct s_main_data
{
	t_ast		*ast;
	char		*line;
	char		*prompt;
	t_tokens	*tokens_list;
}				t_main_data;

typedef struct s_piping
{
	int		num_pipes;
	int		*p;
	int		*pid;
	int		wait;
	int		pid_index;
	int		dup1;
	int		dup02;
	int		pipe_index;
	int		i;
}				t_piping;

#endif