/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list_of_matched_files_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:51:03 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:12:27 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline_bonus.h"

void	print_spaces(int count)
{
	while (count > 0)
	{
		write(1, " ", 1);
		count--;
	}
}

void	print_curr_file_with_colors(t_rdline *r_vars, t_tab_vars *t_vars, int i)
{
	char			*file_full_path;
	struct stat		file_stat;
	int				file_len;
	int				spaces;

	file_len = ft_strlen(t_vars->matched_files.elements[i]);
	spaces = t_vars->max_file_case_len - file_len;
	file_full_path = ft_strjoin(t_vars->dir_to_search,
			t_vars->matched_files.elements[i]);
	stat(file_full_path, &file_stat);
	free(file_full_path);
	if (S_ISDIR(file_stat.st_mode))
		write(1, PRP, ft_strlen(PRP));
	else if (file_stat.st_mode & S_IXUSR)
		write(1, GRN, ft_strlen(GRN));
	write(1, t_vars->matched_files.elements[i], file_len);
	write(1, WHT, ft_strlen(WHT));
	if (S_ISDIR(file_stat.st_mode))
	{
		write(1, "/", 1);
		file_len += 1;
		spaces -= 1;
	}
	print_spaces(spaces);
	r_vars->curs_colm_pos += (file_len + spaces);
}

void	print_file_with_hiliting(t_rdline *r_vars, t_tab_vars *t_vars, int i)
{
	int				file_len;
	int				hilited_spaces;
	char			*file_full_path;
	struct stat		file_stat;

	file_len = ft_strlen(t_vars->matched_files.elements[i]);
	hilited_spaces = t_vars->max_file_case_len - file_len - 2;
	file_full_path = ft_strjoin(t_vars->dir_to_search,
			t_vars->matched_files.elements[i]);
	stat(file_full_path, &file_stat);
	free(file_full_path);
	tputs(r_vars->capability.enter_standout_mode, 1, put_char);
	write(1, t_vars->matched_files.elements[i], file_len);
	write(1, WHT, ft_strlen(WHT));
	if (S_ISDIR(file_stat.st_mode))
	{
		write(1, "/", 1);
		file_len += 1;
		hilited_spaces -= 1;
	}
	print_spaces(hilited_spaces);
	r_vars->curs_colm_pos += (file_len + hilited_spaces);
	tputs(r_vars->capability.leave_standout_mode, 1, put_char);
	write(1, "  ", 2);
	r_vars->curs_colm_pos += 2;
}

void	print_list_of_matched_files(t_rdline *rdl_vars, t_tab_vars *tab_vars)
{
	int		i;
	int		screen_w;

	i = 0;
	screen_w = rdl_vars->width_of_screen;
	save_curr_cursor_pos(rdl_vars);
	move_cursor_to_end_of_printed_line(rdl_vars);
	move_cursor_start_of_next_line(rdl_vars);
	while (i < tab_vars->matched_files.used_size)
	{
		if (rdl_vars->curs_colm_pos + tab_vars->max_file_case_len > screen_w)
			move_cursor_start_of_next_line(rdl_vars);
		if (i == tab_vars->curr_index && rdl_vars->tab_mode == on)
			print_file_with_hiliting(rdl_vars, tab_vars, i);
		else
			print_curr_file_with_colors(rdl_vars, tab_vars, i);
		i++;
	}
	if (rdl_vars->curs_colm_pos + tab_vars->max_file_case_len > screen_w)
		move_cursor_start_of_next_line(rdl_vars);
	clear_curr_line_after_and_below_cursor(rdl_vars);
	restore_cursor_pos(rdl_vars);
}
