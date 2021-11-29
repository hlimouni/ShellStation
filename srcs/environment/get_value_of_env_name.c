/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_of_env_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:46:15 by iltafah           #+#    #+#             */
/*   Updated: 2021/11/11 23:22:46 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./environment.h"

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

int	get_index_of_env_name(t_env_table env_table, char *name)
{
	int		i;

	i = 0;
	while (env_table.name.elements[i] != NULL)
	{
		if (ft_strcmp(env_table.name.elements[i], name) == 0)
			return (i);
		i++;
	}
	return (-1);
}
