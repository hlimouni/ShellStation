/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_element_at_index.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:43:03 by iltafah           #+#    #+#             */
/*   Updated: 2021/12/16 16:07:57 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vectors.h"

void	delete_element_at_index(t_str_vec *vec, int index)
{
	if (vec->used_size == 0 || index < 0 || index > vec->last_index)
		return ;
	free(vec->elements[index]);
	vec->elements[index] = NULL;
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
		realloc_vector(vec);
	}
}
