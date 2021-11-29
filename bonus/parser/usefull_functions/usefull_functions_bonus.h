/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull_functions_bonus.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:37:27 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:04:42 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USEFULL_FUNCTIONS_BONUS_H
# define USEFULL_FUNCTIONS_BONUS_H

# include "./usefull_functions_typedefs_bonus.h"
# include "../parser_bonus.h"

# define SP_SINGLE_QUOTES -1
# define SP_DOUBLE_QUOTES -2
# define SP_BACKSLASH -3

void	initialize_quotes_vars(t_quotes *quotes);
void	open_and_close_double_quotes(t_quotes *quotes);
void	open_and_close_single_quotes(t_quotes *quotes);
void	open_and_close_quotes(char c, t_quotes *quotes);
int		does_backslash_exist(char c, t_quotes *quotes);
int		does_semicolon_exist(char c, t_quotes *quotes);
int		does_pipe_exist(char c, t_quotes *quotes);
void	change_quotes_state(t_quotes *quotes);

#endif
