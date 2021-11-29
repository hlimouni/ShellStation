/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_to_end_of_printed_line.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:50:13 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/02 12:45:54 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline.h"

void	move_cursor_to_end_of_printed_line(t_rdline *rdl_vars)
{
	t_vchar_vec	*history_vec;
	t_char_vec	*history_line;
	int			printed_chars;
	int			col_to_move;
	int			row_to_move;

	history_vec = &rdl_vars->history_vec;
	history_line = &history_vec->elements[rdl_vars->l_i];
	printed_chars = rdl_vars->prompt_len + history_line->used_size;
	if (history_line->used_size > 0)
	{
		col_to_move = printed_chars % rdl_vars->width_of_screen;
		row_to_move = printed_chars / rdl_vars->width_of_screen;
		move_cursor_to_colum_and_row(rdl_vars, col_to_move, row_to_move);
	}
}
