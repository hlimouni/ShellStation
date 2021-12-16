/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_typedefs.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 21:54:28 by iltafah           #+#    #+#             */
/*   Updated: 2021/12/16 08:07:40 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_TYPEDEFS_H
# define MINISHELL_TYPEDEFS_H

# include "./readline/readline.h"

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

#endif