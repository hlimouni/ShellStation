/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enter_tab_mode_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 21:39:50 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:12:43 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline_bonus.h"

void	enter_tab_mode(t_rdline *rdl_vars, t_tab_vars *tab_vars)
{
	initialize_tab_vars(tab_vars);
	tab_vars->dir_to_search = get_dir_to_search(rdl_vars);
	tab_vars->file_to_match = get_file_to_match(rdl_vars);
	initialize_vec_content(&tab_vars->matched_files);
	get_matched_files(tab_vars);
	tab_vars->max_file_case_len = get_max_len(tab_vars->matched_files) + 3;
	if (tab_vars->matched_files.used_size == 0)
	{
		free_tab_vars(tab_vars);
		return ;
	}
	if (tab_vars->file_to_match != NULL)
		tab_vars->printd_matched_file_len = ft_strlen(tab_vars->file_to_match);
	if (tab_vars->matched_files.used_size == 1)
	{
		erase_prec_file(rdl_vars, tab_vars);
		print_matched_file(rdl_vars, tab_vars);
		free_tab_vars(tab_vars);
		return ;
	}
	print_list_of_matched_files(rdl_vars, tab_vars);
	rdl_vars->tab_mode = on;
}
