/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_env_table_to_array_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:46:03 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:07:31 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./environment_bonus.h"

char	**convert_env_table_to_array(t_env_table env_table)
{
	int		i;
	int		size;
	char	**name;
	char	**value;
	char	**env_array;

	i = 0;
	size = env_table.name.used_size + 1;
	env_array = (char **)malloc(sizeof(char *) * size);
	name = env_table.name.elements;
	value = env_table.value.elements;
	while (name[i])
	{
		env_array[i] = ft_strjoin(name[i], value[i]);
		i++;
	}
	env_array[i] = NULL;
	return (env_array);
}
