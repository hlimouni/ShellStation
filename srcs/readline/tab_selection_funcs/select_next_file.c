/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_next_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 21:38:14 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/07 21:38:36 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline.h"

void	select_next_file(t_rdline *rdl_vars, t_tab_vars *tab_vars)
{
	erase_prec_file(rdl_vars, tab_vars);
	print_matched_file(rdl_vars, tab_vars);
	tputs(rdl_vars->capability.make_cursor_invisible, 1, put_char);
	print_list_of_matched_files(rdl_vars, tab_vars);
	tab_vars->curr_index += 1;
	if (tab_vars->curr_index > tab_vars->matched_files.last_index)
		tab_vars->curr_index = 0;
	tputs(rdl_vars->capability.return_cursor_to_normal, 1, put_char);
}
