/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_history_file_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:47:30 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:11:39 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./readline_bonus.h"

int	open_history_file(int o_flag)
{
	char	*hstry_file_path;
	char	*home_directory;
	int		history_fd;

	history_fd = -1;
	home_directory = getenv("HOME");
	if (home_directory != NULL)
	{
		hstry_file_path = ft_strjoin(home_directory, "/.minishell_history");
		history_fd = open(hstry_file_path, o_flag, 0600);
		free(hstry_file_path);
	}
	return (history_fd);
}
