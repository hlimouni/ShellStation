/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_int_vector_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:43:23 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:06:21 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vectors_bonus.h"

void	realloc_int_vector(t_int_vec *vec, int new_size)
{
	int		i;
	int		*new_array;

	i = -1;
	new_array = malloc(sizeof(int) * new_size);
	while (++i < vec->used_size)
		new_array[i] = vec->elements[i];
	free(vec->elements);
	vec->elements = new_array;
}

void	int_vector_free(t_int_vec *vec)
{
	free(vec->elements);
	vec->elements = NULL;
}
