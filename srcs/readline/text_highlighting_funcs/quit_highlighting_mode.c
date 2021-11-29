/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit_highlighting_mode.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:48:19 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/13 19:48:20 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline.h"

static void	move_cursor_left_or_right(t_rdline *rdl_vars, int key)
{
	int	s_hilitd_col;
	int	s_hilitd_row;

	s_hilitd_col = rdl_vars->starting_hilitd_colm;
	s_hilitd_row = rdl_vars->starting_hilitd_row;
	if (key == left_arrow || key == ctl_x)
	{
		if (rdl_vars->starting_hilitd_index < rdl_vars->curr_hilitd_char_index)
		{
			move_cursor_to_colum_and_row(rdl_vars, s_hilitd_col, s_hilitd_row);
			rdl_vars->c_i = rdl_vars->starting_hilitd_index;
		}
	}
	else if (key == right_arrow)
	{
		if (rdl_vars->curr_hilitd_char_index < rdl_vars->starting_hilitd_index)
		{
			move_cursor_to_colum_and_row(rdl_vars, s_hilitd_col, s_hilitd_row);
			rdl_vars->c_i = rdl_vars->starting_hilitd_index;
		}
	}
}

static void	move_curs_to_left_hilitd_pos(t_rdline *rdl_v, int *index)
{
	int	strt_hilitd_col;
	int	strt_hilitd_row;

	strt_hilitd_col = rdl_v->starting_hilitd_colm;
	strt_hilitd_row = rdl_v->starting_hilitd_row;
	if (rdl_v->starting_hilitd_index > rdl_v->curr_hilitd_char_index)
		*index = rdl_v->curr_hilitd_char_index;
	else
	{
		*index = rdl_v->starting_hilitd_index;
		move_cursor_to_colum_and_row(rdl_v, strt_hilitd_col, strt_hilitd_row);
	}
}

void	quit_highlighting_mode(t_rdline *rdl_vars, int key)
{
	t_vchar_vec		*history_vec;
	char			*hstry_str;
	int				higligtd_beg_i;

	if (rdl_vars->reverse_video_mode == 1)
	{
		history_vec = &rdl_vars->history_vec;
		hstry_str = history_vec->elements[rdl_vars->l_i].elements;
		save_curr_cursor_pos(rdl_vars);
		move_curs_to_left_hilitd_pos(rdl_vars, &higligtd_beg_i);
		tputs(rdl_vars->capability.return_cursor_to_normal, 1, put_char);
		tputs(rdl_vars->capability.leave_standout_mode, 1, put_char);
		print_line_with_chosen_method(rdl_vars, hstry_str + higligtd_beg_i,
			dont_restore);
		restore_cursor_pos(rdl_vars);
		move_cursor_left_or_right(rdl_vars, key);
		rdl_vars->reverse_video_mode = 0;
	}
}
