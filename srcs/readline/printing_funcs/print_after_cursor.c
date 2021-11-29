/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_after_cursor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:49:29 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/09 12:11:29 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline.h"

void	print_after_cursor(t_rdline *rdl_vars, char *str, int option)
{
	int		len;
	int		screen_w;

	len = ft_strlen(str);
	screen_w = rdl_vars->width_of_screen;
	if (option == restore)
		save_curr_cursor_pos(rdl_vars);
	clear_curr_line_after_cursor(rdl_vars);
	write(1, str, len);
	if (len < (screen_w - rdl_vars->curs_colm_pos))
		rdl_vars->curs_colm_pos += len;
	else
	{
		rdl_vars->curs_row_pos += (len + rdl_vars->curs_colm_pos) / screen_w;
		rdl_vars->curs_colm_pos = (len + rdl_vars->curs_colm_pos) % screen_w;
		if (rdl_vars->curs_colm_pos == 0)
		{
			put_char(' ');
			rdl_vars->curs_colm_pos++;
			move_cursor_left(rdl_vars);
		}
	}
	clear_curr_line_after_cursor(rdl_vars);
	if (option == restore)
		restore_cursor_pos(rdl_vars);
}
