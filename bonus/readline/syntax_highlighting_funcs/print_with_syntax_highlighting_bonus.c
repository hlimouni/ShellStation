/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_with_syntax_highlighting_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:48:49 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:12:49 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline_bonus.h"

static int	is_there_syntax_error(t_quotes *vars, char c)
{
	if (vars->pipe == EXIST && (c == PIPE || c == SEMICOLON))
		return (ERROR);
	else if (vars->semicolon == EXIST && (c == SEMICOLON || c == PIPE))
		return (ERROR);
	return (TRUE);
}

static char	*get_cmd_color(char *line, int *len)
{
	char	*color;
	char	*cmd;

	color = RED_MAX;
	while (line[*len] != '\0' && line[*len] != ' ')
		(*len)++;
	cmd = ft_substr(line, 0, *len);
	if (check_if_file_exist(cmd) == EXIST)
		color = GRN;
	else if (check_if_cmd_exist(cmd) == EXIST)
		color = GRN;
	free(cmd);
	return (color);
}

static char	*get_highlighting_color(t_quotes *vars, char *line, int i, int *len)
{
	char	*color;

	color = WHT;
	open_and_close_quotes(line[i], vars);
	change_quotes_state(vars);
	if ((i == 0 || vars->pipe == EXIST || vars->semicolon == EXIST))
		color = get_cmd_color(line + i, len);
	if (is_there_syntax_error(vars, line[i]) == ERROR)
		return (RED_MAX);
	if (vars->curr_state != vars->old_state)
		color = PNK;
	else if (vars->double_quotes == OPEND || vars->single_quotes == OPEND)
		color = PRP;
	if (does_pipe_exist(line[i], vars) == EXIST)
		color = YEL;
	if (does_semicolon_exist(line[i], vars) == EXIST)
		color = CYN;
	if (does_backslash_exist(line[i], vars) == EXIST)
		color = ORN;
	return (color);
}

static void	start_printing(t_rdline *rdl_vars)
{
	int				i;
	int				len;
	char			*color;
	t_char_vec		*hstry_line;
	t_quotes		syntax_vars;

	i = 0;
	len = 0;
	hstry_line = &rdl_vars->history_vec.elements[rdl_vars->l_i];
	initialize_quotes_vars(&syntax_vars);
	while (i < hstry_line->used_size)
	{
		if (len == 0)
			color = get_highlighting_color(&syntax_vars, hstry_line->elements,
					i, &len);
		else
			len--;
		rdl_print_char(rdl_vars, hstry_line->elements[i], color);
		i++;
	}
}

void	print_with_syntax_highlighting(t_rdline *rdl_vars, int option)
{
	if (option == restore)
		save_curr_cursor_pos(rdl_vars);
	tputs(rdl_vars->capability.make_cursor_invisible, 1, put_char);
	move_cursor_to_colum_and_row(rdl_vars, rdl_vars->prompt_len, 0);
	start_printing(rdl_vars);
	clear_curr_line_after_and_below_cursor(rdl_vars);
	tputs(rdl_vars->capability.return_cursor_to_normal, 1, put_char);
	if (option == restore)
		restore_cursor_pos(rdl_vars);
	write(1, WHT, ft_strlen(WHT));
}
