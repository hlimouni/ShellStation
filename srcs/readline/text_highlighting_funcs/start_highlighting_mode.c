/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_highlighting_mode.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:48:11 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/15 18:35:42 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline.h"

void	start_highlighting_mode(t_rdline *rdl_vars)
{
	if (rdl_vars->reverse_video_mode == 0)
	{
		tputs(rdl_vars->capability.make_cursor_invisible, 1, put_char);
		rdl_vars->curr_hilitd_char_index = rdl_vars->c_i;
		rdl_vars->starting_hilitd_colm = rdl_vars->curs_colm_pos;
		rdl_vars->starting_hilitd_row = rdl_vars->curs_row_pos;
		rdl_vars->starting_hilitd_index = rdl_vars->c_i;
		rdl_vars->reverse_video_mode = 1;
	}
}
