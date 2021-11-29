/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_to_row.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:50:09 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/13 19:50:10 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline.h"

void	move_cursor_to_row(t_rdline *rdl_vars, int row)
{
	if (rdl_vars->curs_row_pos != row)
	{
		if (row >= 0)
		{
			if (rdl_vars->curs_row_pos < row)
			{
				while (rdl_vars->curs_row_pos < row)
					move_cursor_down_vertically(rdl_vars);
			}
			else
			{
				while (rdl_vars->curs_row_pos > row)
					move_cursor_up_vertically(rdl_vars);
			}
		}
	}
}
