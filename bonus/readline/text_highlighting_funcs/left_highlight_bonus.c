/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_highlight_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:48:28 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:12:11 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline_bonus.h"

static void	to_be_highlighted_or_not(t_rdline *rdl_v)
{
	if (rdl_v->curr_hilitd_char_index > rdl_v->starting_hilitd_index)
		tputs(rdl_v->capability.leave_standout_mode, 1, put_char);
	else
		tputs(rdl_v->capability.enter_standout_mode, 1, put_char);
}

void	left_highlight(t_rdline *rdl_v)
{
	t_vchar_vec		*hstry_vec;
	t_char_vec		*hstry_line;
	char			char_to_be_hilitd;

	hstry_vec = &rdl_v->history_vec;
	hstry_line = &hstry_vec->elements[rdl_v->l_i];
	char_to_be_hilitd = hstry_line->elements[rdl_v->curr_hilitd_char_index - 1];
	if (rdl_v->curr_hilitd_char_index > 0)
	{
		to_be_highlighted_or_not(rdl_v);
		move_cursor_left_or_up(rdl_v);
		put_colorful_char(char_to_be_hilitd, WHT);
		rdl_v->curs_colm_pos++;
		if (rdl_v->curs_colm_pos == rdl_v->width_of_screen)
			move_cursor_start_of_next_line(rdl_v);
		move_cursor_right_or_down(rdl_v);
		rdl_v->curr_hilitd_char_index--;
		rdl_v->c_i--;
	}
}
