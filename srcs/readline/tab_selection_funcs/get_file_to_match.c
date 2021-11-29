/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_to_match.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:51:44 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/05 13:59:49 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline.h"

char	*get_file_to_match(t_rdline *rdl_vars)
{
	int				i;
	char			*file_to_match;
	t_char_vec		*hstry_line;

	i = rdl_vars->c_i;
	file_to_match = NULL;
	hstry_line = &rdl_vars->history_vec.elements[rdl_vars->l_i];
	while (i != 0 && hstry_line->elements[i - 1] != ' '
		&& hstry_line->elements[i - 1] != '/')
		i--;
	if (rdl_vars->c_i - i > 0)
		file_to_match = ft_substr(hstry_line->elements, i, rdl_vars->c_i - i);
	return (file_to_match);
}
