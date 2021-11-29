/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_of_env_name_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:46:15 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:07:37 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./environment_bonus.h"

char	*get_value_of_env_name(t_env_table env_table, char *name)
{
	int		i;

	i = 0;
	while (env_table.name.elements[i] != NULL)
	{
		if (ft_strcmp(env_table.name.elements[i], name) == 0)
			return (env_table.value.elements[i]);
		i++;
	}
	return (NULL);
}
