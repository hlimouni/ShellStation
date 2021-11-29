/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_left_or_up_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:50:36 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:13:51 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline_bonus.h"

void	move_cursor_left_or_up(t_rdline *rdl_vars)
{
	if (rdl_vars->curs_colm_pos > 0)
		move_cursor_left(rdl_vars);
	else
		move_cursor_end_of_prec_line(rdl_vars);
}
