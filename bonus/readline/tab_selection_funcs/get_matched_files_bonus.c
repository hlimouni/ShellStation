/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_matched_files_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:53:14 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:12:33 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline_bonus.h"

void	get_matched_files(t_tab_vars *vars)
{
	struct dirent	*entry;
	DIR				*curr_directory;

	curr_directory = opendir(vars->dir_to_search);
	if (curr_directory == NULL)
		return ;
	while (true)
	{
		entry = readdir(curr_directory);
		if (entry == NULL)
			break ;
		if (vars->file_to_match != NULL)
		{
			if (ft_strncmp(vars->file_to_match, entry->d_name,
					ft_strlen(vars->file_to_match)) == 0)
				vars->matched_files.add_new_element(&vars->matched_files,
					ft_strdup(entry->d_name));
		}
		else if (entry->d_name[0] != '.')
			vars->matched_files.add_new_element(&vars->matched_files,
				ft_strdup(entry->d_name));
	}
	closedir(curr_directory);
	return ;
}
