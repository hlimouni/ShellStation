/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dollar_value_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 21:47:39 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:10:30 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expanding_bonus.h"

char	*get_dollar_value(char *name)
{
	int			i;
	char		*value;
	t_str_vec	name_vec;
	t_str_vec	value_vec;

	i = 0;
	value = NULL;
	if (name[0] == '?')
		value = convert_int_to_str(g_vars.last_err_num);
	else
	{
		name_vec = g_vars.env_table.name;
		value_vec = g_vars.env_table.value;
		while (name_vec.elements[i])
		{
			if (ft_strcmp(name, name_vec.elements[i]) == 0)
			{
				if (value_vec.elements[i] != NULL)
					value = ft_strdup(value_vec.elements[i]);
				break ;
			}
			i++;
		}
	}
	return (value);
}
