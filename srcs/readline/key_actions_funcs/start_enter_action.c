/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_enter_action.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:51:14 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/15 17:28:58 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline.h"

void	reset_colors(void)
{
	write(1, RST, ft_strlen(RST));
}

void	exit_tab_mode(t_rdline *rl_vars)
{
	t_char_vec		*hstry_line;

	hstry_line = &rl_vars->history_vec.elements[rl_vars->l_i];
	clear_curr_line_after_and_below_cursor(rl_vars);
	if (hstry_line->elements[rl_vars->c_i - 1] != '/')
		print_curr_char(rl_vars, ' ');
	rl_vars->tab_vars.matched_files.free(&rl_vars->tab_vars.matched_files);
	if (rl_vars->tab_vars.dir_to_search != NULL)
		free(rl_vars->tab_vars.dir_to_search);
	if (rl_vars->tab_vars.file_to_match != NULL)
		free(rl_vars->tab_vars.file_to_match);
	rl_vars->previous_key = disable_enter;
	rl_vars->tab_mode = off;
}

void	start_enter_action(t_rdline *rl_vars)
{
	if (rl_vars->tab_mode == on)
		exit_tab_mode(rl_vars);
	else
	{
		rl_vars->previous_key = enter;
		quit_highlighting_mode(rl_vars, enter);
		insert_curr_line_to_history(rl_vars);
		move_cursor_to_end_of_printed_line(rl_vars);
		if (rl_vars->auto_suggestions == on)
			erase_suggestions(rl_vars);
		reset_colors();
		put_char('\n');
	}
}
