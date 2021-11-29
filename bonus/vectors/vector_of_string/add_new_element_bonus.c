/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_element_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:43:10 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:06:12 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vectors_bonus.h"

void	add_new_element(t_str_vec *vec, char *element)
{
	if (vec->used_size == vec->size)
	{
		vec->size *= 2;
		realloc_vector(vec);
	}
	vec->elements[vec->used_size] = element;
	vec->elements[vec->used_size + 1] = NULL;
	vec->used_size += 1;
	vec->last_index = vec->used_size - 1;
}
