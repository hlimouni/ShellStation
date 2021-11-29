/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:43:53 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/13 19:43:55 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vectors.h"

void	add_new_int(t_int_vec *vec, int num)
{
	if (vec->used_size == vec->size)
	{
		vec->size *= 2;
		realloc_int_vector(vec, vec->size);
	}
	vec->elements[vec->used_size] = num;
	vec->used_size += 1;
	if (vec->used_size > 0)
		vec->last_index = vec->used_size - 1;
}
