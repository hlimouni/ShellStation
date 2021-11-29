/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:44:31 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/19 21:45:10 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vectors.h"

void	add_new_char(t_char_vec *vec, char c)
{
	if (vec->used_size == vec->size)
	{
		vec->size *= 2;
		realloc_char_vector(vec, vec->size);
	}
	vec->elements[vec->used_size] = c;
	vec->elements[vec->used_size + 1] = '\0';
	vec->used_size += 1;
	if (vec->used_size > 0)
		vec->last_index = vec->used_size - 1;
}
