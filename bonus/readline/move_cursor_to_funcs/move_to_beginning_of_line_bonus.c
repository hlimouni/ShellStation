/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_beginning_of_line_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:49:51 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:13:29 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline_bonus.h"

void	move_to_beginning_of_line(t_rdline *rdl_vars)
{
	if (rdl_vars->c_i > 0)
	{
		while (rdl_vars->curs_row_pos > 0)
			move_cursor_up_vertically(rdl_vars);
		move_cursor_to_colum(rdl_vars, rdl_vars->prompt_len);
		rdl_vars->c_i = 0;
	}
}
