/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_to_colum_and_row.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:50:21 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/13 19:50:23 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline.h"

void	move_cursor_to_colum_and_row(t_rdline *rdl_vars, int col, int row)
{
	move_cursor_to_colum(rdl_vars, col);
	move_cursor_to_row(rdl_vars, row);
}
