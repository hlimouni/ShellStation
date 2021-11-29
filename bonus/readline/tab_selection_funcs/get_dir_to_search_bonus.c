/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dir_to_search_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:52:15 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:12:37 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline_bonus.h"

char	*get_dir_to_search(t_rdline *rdl_vars)
{
	int				i;
	int				start;
	int				end;
	char			*dir_to_search;
	t_char_vec		*hstry_line;

	i = rdl_vars->c_i;
	dir_to_search = NULL;
	hstry_line = &rdl_vars->history_vec.elements[rdl_vars->l_i];
	while (i != 0 && hstry_line->elements[i - 1] != ' ')
		i--;
	start = i;
	end = start;
	while (hstry_line->elements[i] != ' ' && hstry_line->elements[i] != '\0')
	{
		if (hstry_line->elements[i] == '/')
			end = i + 1;
		i++;
	}
	if (end - start > 0)
		dir_to_search = ft_substr(hstry_line->elements, start, end - start);
	else
		dir_to_search = ft_strdup("./");
	return (dir_to_search);
}
