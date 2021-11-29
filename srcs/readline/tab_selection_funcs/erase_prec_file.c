/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase_prec_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:49:34 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/05 13:49:58 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline.h"

void	erase_prec_file(t_rdline *rdl_vars, t_tab_vars *tab_vars)
{
	t_char_vec		*hstry_line;

	hstry_line = &rdl_vars->history_vec.elements[rdl_vars->l_i];
	while (tab_vars->printd_matched_file_len > 0)
	{
		rdl_vars->c_i--;
		hstry_line->delete_element_at_index(hstry_line, rdl_vars->c_i);
		if (rdl_vars->curs_colm_pos == 0)
			move_cursor_end_of_prec_line(rdl_vars);
		else
			move_cursor_left(rdl_vars);
		tab_vars->printd_matched_file_len--;
	}
}
