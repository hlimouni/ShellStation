/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array_of_pointers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:45:50 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/13 19:45:51 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./freeing_time.h"

void	free_array(char ***array_addr)
{
	int		i;
	char	**array;

	i = 0;
	array = *array_addr;
	while (array[i])
		free(array[i++]);
	free(*array_addr);
	*array_addr = NULL;
}
