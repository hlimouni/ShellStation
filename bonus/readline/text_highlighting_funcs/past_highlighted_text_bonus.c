/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   past_highlighted_text_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:48:23 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:12:09 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline_bonus.h"

void	past_highlighted_text(t_rdline *rdl_vars)
{
	t_vchar_vec		*hstry_vec;
	t_char_vec		*hstry_line;
	char			*hstry_str;
	int				line_i;
	int				char_i;

	if (rdl_vars->hilitd_txt != NULL)
	{
		char_i = rdl_vars->c_i;
		line_i = rdl_vars->l_i;
		hstry_vec = &rdl_vars->history_vec;
		hstry_line = hstry_vec->elements;
		hstry_line[line_i].add_set_of_elements_at_index(&hstry_line[line_i],
			rdl_vars->hilitd_txt, char_i);
		hstry_str = hstry_line[rdl_vars->l_i].elements;
		print_line_with_chosen_method(rdl_vars, hstry_str + char_i, restore);
		update_cursor_data(rdl_vars);
		if (rdl_vars->auto_suggestions == on)
			print_suggestions(rdl_vars);
	}
}
