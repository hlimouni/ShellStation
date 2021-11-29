/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_last_char_vec_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:44:52 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:07:21 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vectors_bonus.h"

void	delete_last_char_vec(t_vchar_vec *vec)
{
	if (vec->used_size > 0)
	{
		free(vec->elements[vec->last_index].elements);
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
}
