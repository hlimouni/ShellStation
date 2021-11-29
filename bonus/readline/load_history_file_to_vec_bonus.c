/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_history_file_to_vec_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:47:35 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:11:41 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./readline_bonus.h"

void	load_history(t_rdline *rdl_vars)
{
	char			*line;
	t_char_vec		new_vec;
	int				history_fd;
	t_vchar_vec		*history_vec;
	int				is_not_last_line;

	history_fd = open_history_file((O_CREAT | O_RDONLY));
	if (history_fd == -1)
		return ;
	history_vec = &rdl_vars->history_vec;
	is_not_last_line = true;
	while (is_not_last_line == true)
	{
		is_not_last_line = get_next_line(history_fd, &line);
		if (is_not_last_line == true)
		{
			new_vec = convert_string_to_char_vec(line);
			history_vec->add_new_element(history_vec, new_vec);
		}
		if (is_not_last_line != -1)
			free(line);
	}
	close(history_fd);
}
