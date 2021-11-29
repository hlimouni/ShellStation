/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_tab_vars_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 21:51:21 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:12:29 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline_bonus.h"

void	initialize_tab_vars(t_tab_vars *vars)
{
	vars->curr_index = 0;
	vars->max_file_case_len = 0;
	vars->printd_matched_file_len = 0;
	vars->dir_to_search = NULL;
	vars->file_to_match = NULL;
}
