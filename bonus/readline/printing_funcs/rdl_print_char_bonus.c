/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdl_print_char_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:49:02 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:12:56 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline_bonus.h"

void	rdl_print_char(t_rdline *rdl_vars, char c, char *color)
{
	put_colorful_char(c, color);
	rdl_vars->curs_colm_pos++;
	if (rdl_vars->curs_colm_pos == rdl_vars->width_of_screen)
	{
		put_char(' ');
		move_cursor_left(rdl_vars);
		rdl_vars->curs_row_pos++;
		rdl_vars->curs_colm_pos = 0;
		clear_curr_line_after_cursor(rdl_vars);
	}
}
