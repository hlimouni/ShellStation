/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_start_of_next_line_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:50:25 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:13:45 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline_bonus.h"

void	move_cursor_start_of_next_line(t_rdline *rdl_vars)
{
	move_cursor_to_colum(rdl_vars, 0);
	move_cursor_down_vertically(rdl_vars);
}
