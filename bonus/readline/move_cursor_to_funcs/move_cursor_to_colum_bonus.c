/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_to_colum_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:50:17 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:13:41 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline_bonus.h"

void	move_cursor_to_colum(t_rdline *rdl_vars, int col)
{
	tputs(tgoto(rdl_vars->capability.mv_cursor_to_colm, 0, col), 1, put_char);
	rdl_vars->curs_colm_pos = col;
}
