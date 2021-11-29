/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_left_right.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:50:32 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/13 19:50:34 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline.h"

void	move_cursor_right(t_rdline *rdl_vars)
{
	tputs(rdl_vars->capability.mv_cursor_right, 1, put_char);
	rdl_vars->curs_colm_pos++;
}

void	move_cursor_left(t_rdline *rdl_vars)
{
	tputs(rdl_vars->capability.mv_cursor_left, 1, put_char);
	rdl_vars->curs_colm_pos--;
}
