/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_next_word_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:49:42 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:13:24 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline_bonus.h"

void	skip_chars_to_the_right(t_rdline *rdl_vars, char *line)
{
	int	*c_i;

	c_i = &rdl_vars->c_i;
	while (line[*c_i] != ' ' && line[*c_i] != '\0')
	{
		if (rdl_vars->curs_colm_pos < rdl_vars->width_of_screen - 1)
			move_cursor_right(rdl_vars);
		else
			move_cursor_start_of_next_line(rdl_vars);
		(*c_i)++;
	}
}

void	skip_spaces_to_the_right(t_rdline *rdl_vars, char *line)
{
	int	*c_i;

	c_i = &rdl_vars->c_i;
	while (line[*c_i] == ' ')
	{
		if (rdl_vars->curs_colm_pos < rdl_vars->width_of_screen - 1)
			move_cursor_right(rdl_vars);
		else
			move_cursor_start_of_next_line(rdl_vars);
		(*c_i)++;
	}
}

void	move_to_next_word(t_rdline *rdl_vars)
{
	t_vchar_vec		*history_vec;
	t_char_vec		*history_line;
	char			*curr_hstry_line;
	int				*c_i;
	int				*l_i;

	c_i = &rdl_vars->c_i;
	l_i = &rdl_vars->l_i;
	history_vec = &rdl_vars->history_vec;
	history_line = history_vec->elements;
	curr_hstry_line = history_line[*l_i].elements;
	if (*c_i <= history_line[*l_i].last_index)
	{
		skip_chars_to_the_right(rdl_vars, curr_hstry_line);
		skip_spaces_to_the_right(rdl_vars, curr_hstry_line);
	}
}
