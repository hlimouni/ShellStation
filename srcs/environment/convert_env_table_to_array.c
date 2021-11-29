/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_env_table_to_array.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:46:03 by iltafah           #+#    #+#             */
/*   Updated: 2021/11/22 21:40:32 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./environment.h"

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

