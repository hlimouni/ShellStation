/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_and_remove_char_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:47:52 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:11:53 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_bonus.h"

void	erase_and_remove_curr_char(t_rdline *rdl_vars)
{
	t_vchar_vec		*history_vec;
	t_char_vec		*hstry_line;
	int				*curs_colm_pos;
	int				*l_i;
	int				*c_i;

	c_i = &rdl_vars->c_i;
	l_i = &rdl_vars->l_i;
	history_vec = &rdl_vars->history_vec;
	hstry_line = history_vec->elements;
	curs_colm_pos = &rdl_vars->curs_colm_pos;
	if (*c_i > 0)
	{
		(*c_i)--;
		hstry_line[*l_i].delete_element_at_index(&hstry_line[*l_i], *c_i);
		if (*curs_colm_pos == 0)
			move_cursor_end_of_prec_line(rdl_vars);
		else
			move_cursor_left(rdl_vars);
		print_line_with_chosen_method(rdl_vars,
			hstry_line[*l_i].elements + *c_i, restore);
		if (rdl_vars->auto_suggestions == on)
			print_suggestions(rdl_vars);
		update_cursor_data(rdl_vars);
	}
}
