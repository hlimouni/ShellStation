/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_up_down_vertically.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:50:05 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/13 19:50:06 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline.h"

void	move_cursor_up_vertically(t_rdline *rdl_vars)
{
	tputs(rdl_vars->capability.mv_cursor_up_vertically, 1, put_char);
	rdl_vars->curs_row_pos--;
}

void	move_cursor_down_vertically(t_rdline *rdl_vars)
{
	tputs(rdl_vars->capability.mv_cursor_down_vertically, 1, put_char);
	move_cursor_to_colum(rdl_vars, rdl_vars->curs_colm_pos);
	rdl_vars->curs_row_pos++;
}
