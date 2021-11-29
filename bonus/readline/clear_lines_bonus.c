/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_lines_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:48:05 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:12:00 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_bonus.h"

void	clear_curr_line_after_cursor(t_rdline *rdl_vars)
{
	tputs(rdl_vars->capability.clear_line_after_cursor, 1, put_char);
}

void	clear_curr_line_and_below_cursor(t_rdline *rdl_vars)
{
	move_cursor_to_colum(rdl_vars, 0);
	tputs(rdl_vars->capability.clear_lines_below, 1, put_char);
}

void	clear_curr_line_after_and_below_cursor(t_rdline *rdl_vars)
{
	save_curr_cursor_pos(rdl_vars);
	clear_curr_line_after_cursor(rdl_vars);
	move_cursor_start_of_next_line(rdl_vars);
	clear_curr_line_and_below_cursor(rdl_vars);
	restore_cursor_pos(rdl_vars);
}

void	clear_printed_lines(t_rdline *rdl_vars, int option)
{
	save_curr_cursor_pos(rdl_vars);
	while (rdl_vars->curs_row_pos > 0)
		move_cursor_up_vertically(rdl_vars);
	clear_curr_line_and_below_cursor(rdl_vars);
	print_prompt(rdl_vars);
	rdl_vars->curs_colm_pos = rdl_vars->prompt_len;
	if (option == restore)
		restore_cursor_pos(rdl_vars);
}
