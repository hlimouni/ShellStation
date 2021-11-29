/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_tab_action.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 21:36:33 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/07 21:36:54 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline.h"

void	start_tab_action(t_rdline *rdl_vars)
{
	t_char_vec		*hstry_line;

	hstry_line = &rdl_vars->history_vec.elements[rdl_vars->l_i];
	if (rdl_vars->tab_mode == off)
	{
		if (hstry_line->elements[rdl_vars->c_i] != ' '
			&& hstry_line->elements[rdl_vars->c_i] != '\0')
			return ;
		enter_tab_mode(rdl_vars, &rdl_vars->tab_vars);
	}
	else
		select_next_file(rdl_vars, &rdl_vars->tab_vars);
	rdl_vars->previous_key = tab;
}
