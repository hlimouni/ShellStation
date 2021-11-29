/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab_vars_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 21:40:34 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:12:39 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline_bonus.h"

void	free_tab_vars(t_tab_vars *tab_vars)
{
	if (tab_vars->dir_to_search != NULL)
		free(tab_vars->dir_to_search);
	if (tab_vars->file_to_match != NULL)
		free(tab_vars->file_to_match);
	tab_vars->matched_files.free(&tab_vars->matched_files);
}
