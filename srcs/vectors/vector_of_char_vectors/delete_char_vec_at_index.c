/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_char_vec_at_index.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:44:56 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/13 19:44:58 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vectors.h"

void	delete_char_vec_at_index(t_vchar_vec *vec, int index)
{
	if (vec->used_size == 0 || index < 0 || index > vec->last_index)
		return ;
	free(vec->elements[index].elements);
	vec->elements[index].elements = NULL;
	while (index < vec->last_index)
	{
		vec->elements[index] = vec->elements[index + 1];
		index++;
	}
	vec->used_size -= 1;
	if (vec->used_size > 0)
		vec->last_index = vec->used_size - 1;
	else
		vec->last_index = 0;
	if (vec->size > 0 && vec->used_size < (vec->size / 4))
	{
		vec->size /= 2;
		realloc_vector_of_char_vec(vec);
	}
}
