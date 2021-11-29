/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matched_file_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:50:21 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:12:25 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline_bonus.h"

void	add_slash_if_directory(t_rdline *rdl_vars, t_tab_vars *tab_vars)
{
	char			*file_full_path;
	char			*curr_matched_file;
	t_char_vec		*hstry_line;
	struct stat		file_stat;

	hstry_line = &rdl_vars->history_vec.elements[rdl_vars->l_i];
	curr_matched_file = tab_vars->matched_files.elements[tab_vars->curr_index];
	file_full_path = ft_strjoin(tab_vars->dir_to_search, curr_matched_file);
	stat(file_full_path, &file_stat);
	if (S_ISDIR(file_stat.st_mode))
	{
		hstry_line->add_new_element_at_index(hstry_line, '/', rdl_vars->c_i);
		print_after_cursor(rdl_vars, "/", dont_restore);
		tab_vars->printd_matched_file_len += 1;
		rdl_vars->c_i += 1;
	}	
	free(file_full_path);
}

void	print_matched_file(t_rdline *rdl_vars, t_tab_vars *tab_vars)
{
	t_char_vec		*hstry_line;
	char			*curr_matched_file;

	hstry_line = &rdl_vars->history_vec.elements[rdl_vars->l_i];
	curr_matched_file = tab_vars->matched_files.elements[tab_vars->curr_index];
	hstry_line->add_set_of_elements_at_index(hstry_line, curr_matched_file,
		rdl_vars->c_i);
	rdl_vars->c_i += ft_strlen(curr_matched_file);
	tab_vars->printd_matched_file_len = ft_strlen(curr_matched_file);
	print_after_cursor(rdl_vars, curr_matched_file, dont_restore);
	add_slash_if_directory(rdl_vars, tab_vars);
	print_after_cursor(rdl_vars, hstry_line->elements + rdl_vars->c_i, restore);
	update_cursor_data(rdl_vars);
}
