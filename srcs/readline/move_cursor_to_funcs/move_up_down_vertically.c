/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up_down_vertically.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:49:34 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/13 19:49:35 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline.h"

void	move_up_vertically(t_rdline *rdl_vars)
{
	if (rdl_vars->curs_row_pos > 0)
	{
		if (rdl_vars->curs_row_pos == 1)
		{
			if (rdl_vars->curs_colm_pos < rdl_vars->prompt_len)
			{
				rdl_vars->c_i = 0;
				move_cursor_to_colum(rdl_vars, rdl_vars->prompt_len);
			}
			else
				rdl_vars->c_i -= rdl_vars->width_of_screen;
		}
		else
			rdl_vars->c_i -= rdl_vars->width_of_screen;
		move_cursor_up_vertically(rdl_vars);
	}
}

void	move_down_vertically(t_rdline *rdl_vars)
{
	int				last_row;
	int				hstry_line_len;
	int				printed_chars_after_curs;
	int				printed_chars_at_last_line;
	t_vchar_vec		*history_vec;

	history_vec = &rdl_vars->history_vec;
	last_row = rdl_vars->printed_lines - 1;
	hstry_line_len = history_vec->elements[rdl_vars->l_i].used_size;
	printed_chars_after_curs = hstry_line_len - rdl_vars->c_i;
	printed_chars_at_last_line = printed_chars_after_curs
		- (rdl_vars->width_of_screen - rdl_vars->curs_colm_pos);
	if (rdl_vars->curs_row_pos < last_row)
	{
		move_cursor_down_vertically(rdl_vars);
		if (printed_chars_after_curs > rdl_vars->width_of_screen)
			rdl_vars->c_i = rdl_vars->c_i + rdl_vars->width_of_screen;
		else
		{
			rdl_vars->c_i = hstry_line_len;
			move_cursor_to_colum(rdl_vars, printed_chars_at_last_line);
		}
	}
}
