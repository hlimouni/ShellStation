/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quoted_var_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 09:03:30 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:31:12 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./expanding_bonus.h"

int	expand_quoted_var(char *str, int *i, t_char_vec *vec)
{
	char		*name;
	char		*value;
	int			is_expanded;

	is_expanded = false;
	name = get_dollar_name(str, i);
	if (name != NULL)
	{
		value = get_dollar_value(name);
		vec->add_set_of_elements_at_index(vec, value, vec->used_size);
		is_expanded = true;
		free(name);
		free(value);
	}
	return (is_expanded);
}
