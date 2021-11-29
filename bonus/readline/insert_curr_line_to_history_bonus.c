/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_curr_line_to_history_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:47:39 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:11:43 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_bonus.h"

void	append_curr_line_to_history(t_rdline *rdl_vars)
{
	t_char_vec		*hstry_line;
	t_vchar_vec		*hstry_vec;
	t_char_vec		new_vec;
	int				*l_i;

	l_i = &rdl_vars->l_i;
	hstry_vec = &rdl_vars->history_vec;
	hstry_line = hstry_vec->elements;
	initialize_vec_of_char(&new_vec);
	new_vec.add_set_of_elements(&new_vec, hstry_line[*l_i].elements);
	hstry_vec->delete_last_element(hstry_vec);
	hstry_vec->add_new_element(hstry_vec, new_vec);
}

void	restore_old_history_of_curr_line(t_rdline *rdl_vars)
{
	char			**old_history;
	t_vchar_vec		*history_vec;
	t_char_vec		old_line;
	int				*l_i;

	l_i = &rdl_vars->l_i;
	history_vec = &rdl_vars->history_vec;
	old_history = rdl_vars->old_history;
	if (rdl_vars->old_history[*l_i] != NULL)
	{
		initialize_vec_of_char(&old_line);
		old_line.add_set_of_elements(&old_line, old_history[*l_i]);
		history_vec->delete_element_at_index(history_vec, *l_i);
		history_vec->add_new_element_at_index(history_vec, old_line, *l_i);
	}
}

void	insert_curr_line_to_history(t_rdline *rdl_vars)
{
	t_char_vec		*history_line;
	t_vchar_vec		*history_vec;
	int				*l_i;

	history_vec = &rdl_vars->history_vec;
	history_line = history_vec->elements;
	l_i = &rdl_vars->l_i;
	rdl_vars->line = strdup(history_line[*l_i].elements);
	if (history_line[*l_i].used_size > 0)
		append_curr_line_to_history(rdl_vars);
	else
		history_vec->delete_last_element(history_vec);
	restore_old_history_of_curr_line(rdl_vars);
}
