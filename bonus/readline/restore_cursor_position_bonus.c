/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_cursor_position_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:47:06 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:11:30 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_bonus.h"

void	restore_cursor_pos(t_rdline *rdl_vars)
{
	t_int_vec	*old_colm_stack;
	t_int_vec	*old_row_stack;
	int			old_curs_colm_pos;
	int			old_curs_row_pos;

	old_colm_stack = &rdl_vars->old_curs_colm_pos_stack;
	old_row_stack = &rdl_vars->old_curs_row_pos_stack;
	old_colm_stack->pop_element(old_colm_stack, &old_curs_colm_pos);
	old_row_stack->pop_element(old_row_stack, &old_curs_row_pos);
	while (rdl_vars->curs_row_pos > old_curs_row_pos)
		move_cursor_up_vertically(rdl_vars);
	while (rdl_vars->curs_colm_pos > old_curs_colm_pos)
		move_cursor_left(rdl_vars);
	while (rdl_vars->curs_colm_pos < old_curs_colm_pos)
		move_cursor_right(rdl_vars);
}

void	save_curr_cursor_pos(t_rdline *rdl_vars)
{
	t_int_vec	*old_colm_stack;
	t_int_vec	*old_row_stack;

	old_colm_stack = &rdl_vars->old_curs_colm_pos_stack;
	old_row_stack = &rdl_vars->old_curs_row_pos_stack;
	old_colm_stack->push_element(old_colm_stack, rdl_vars->curs_colm_pos);
	old_row_stack->push_element(old_row_stack, rdl_vars->curs_row_pos);
}
