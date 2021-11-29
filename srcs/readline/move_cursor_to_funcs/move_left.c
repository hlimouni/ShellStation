/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:50:00 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/13 19:50:02 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline.h"

void	move_left(t_rdline *rdl_vars)
{
	int	*curs_colm_pos;
	int	*c_i;

	c_i = &rdl_vars->c_i;
	curs_colm_pos = &rdl_vars->curs_colm_pos;
	if (*c_i > 0)
	{
		(*c_i)--;
		if (*curs_colm_pos == 0)
			move_cursor_end_of_prec_line(rdl_vars);
		else
			move_cursor_left(rdl_vars);
		update_cursor_data(rdl_vars);
	}
}
