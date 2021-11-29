/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tokens_syntax_bonus.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:37:00 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:05:07 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_TOKENS_SYNTAX_BONUS_H
# define CHECK_TOKENS_SYNTAX_BONUS_H

# include "../parser_bonus.h"

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
