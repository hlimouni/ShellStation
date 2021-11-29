/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tokens_syntax.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:37:00 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/15 17:23:43 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_TOKENS_SYNTAX_H
# define CHECK_TOKENS_SYNTAX_H

# include "../parser.h"

typedef struct s_vars
{
	int		backslash;
	int		double_quotes;
	int		single_quotes;
	int		command;
	int		redirection;
	int		pipe;
	int		error;
}	t_vars;

void		check_simple_word_syntax(char *token, t_vars *vars);
void		remember_last_token(t_vars *vars, t_type token);
void		check_pipe_token_order(t_vars *vars);
void		check_semicolon_token_order(t_vars *vars);
void		check_redirection_token_order(t_vars *vars, int type);
void		check_newline_token_order(t_vars *vars);
void		check_word_token_order(t_vars *vars, char *token);

#endif
