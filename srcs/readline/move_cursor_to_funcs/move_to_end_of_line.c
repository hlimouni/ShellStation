/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_end_of_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:49:47 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/13 19:49:48 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline.h"

void	move_to_end_of_line(t_rdline *rdl_vars)
{
	t_vchar_vec	*history_vec;
	t_char_vec	*history_line;
	int			printed_chars;
	int			curs_col_at_last_line;
	int			last_index;

	history_vec = &rdl_vars->history_vec;
	history_line = history_vec->elements;
	last_index = history_line[rdl_vars->l_i].last_index;
	printed_chars = rdl_vars->prompt_len + last_index + 1;
	if (printed_chars > 0 && rdl_vars->c_i <= last_index)
	{
		curs_col_at_last_line = (printed_chars % rdl_vars->width_of_screen);
		while (rdl_vars->curs_row_pos < rdl_vars->printed_lines - 1)
			move_cursor_down_vertically(rdl_vars);
		if (curs_col_at_last_line == 0)
		{
			move_cursor_down_vertically(rdl_vars);
			move_cursor_to_colum(rdl_vars, 0);
		}
		else
			move_cursor_to_colum(rdl_vars, curs_col_at_last_line);
		rdl_vars->c_i = last_index + 1;
	}
}
