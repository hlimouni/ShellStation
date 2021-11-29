/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:49:57 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:13:31 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline_bonus.h"

static void	print_matched_history(t_rdline *vars)
{
	t_char_vec		*history_line;
	t_vchar_vec		*history_vec;
	int				*l_i;
	int				*c_i;

	history_vec = &vars->history_vec;
	history_line = history_vec->elements;
	l_i = &vars->l_i;
	c_i = &vars->c_i;
	if (vars->is_matched_history == true && history_line[*l_i].used_size > 0)
	{
		history_line[*l_i].add_set_of_elements_at_index(&history_line[*l_i],
			history_line[vars->matched_history_index].elements + *c_i, *c_i);
		print_line_with_chosen_method(vars, history_line[*l_i].elements + *c_i,
			dont_restore);
		*c_i = history_line[*l_i].last_index + 1;
		vars->is_matched_history = false;
	}
}

void	move_right(t_rdline *rdl_vars)
{
	t_char_vec		*history_line;
	t_vchar_vec		*history_vec;
	int				*curs_colm_pos;
	int				*l_i;
	int				*c_i;

	history_vec = &rdl_vars->history_vec;
	history_line = history_vec->elements;
	curs_colm_pos = &rdl_vars->curs_colm_pos;
	l_i = &rdl_vars->l_i;
	c_i = &rdl_vars->c_i;
	if (*c_i < history_line[*l_i].used_size)
	{
		(*c_i)++;
		if (*curs_colm_pos == rdl_vars->width_of_screen - 1)
			move_cursor_start_of_next_line(rdl_vars);
		else
			move_cursor_right(rdl_vars);
	}
	else
	{
		if (rdl_vars->auto_suggestions == on)
			print_matched_history(rdl_vars);
	}
	update_cursor_data(rdl_vars);
}
