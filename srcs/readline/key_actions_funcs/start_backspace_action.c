/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_backspace_action.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:51:52 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/09 12:15:15 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline.h"

void	start_backspace_action(t_rdline *rl_vars)
{
	if (rl_vars->tab_mode == on)
	{
		clear_curr_line_after_and_below_cursor(rl_vars);
		rl_vars->tab_vars.matched_files.free(&rl_vars->tab_vars.matched_files);
		if (rl_vars->tab_vars.dir_to_search != NULL)
			free(rl_vars->tab_vars.dir_to_search);
		if (rl_vars->tab_vars.file_to_match != NULL)
			free(rl_vars->tab_vars.file_to_match);
		rl_vars->tab_mode = off;
	}
	quit_highlighting_mode(rl_vars, backspace);
	erase_and_remove_curr_char(rl_vars);
	rl_vars->previous_key = backspace;
}
