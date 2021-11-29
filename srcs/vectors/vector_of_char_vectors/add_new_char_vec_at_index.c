/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_char_vec_at_index.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:45:05 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/19 21:22:17 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vectors.h"

void	add_new_char_vec_at_index(t_vchar_vec *vec, t_char_vec elem, int index)
{
	t_char_vec	last_element;
	int			last_index;

	if (index < 0 || index > vec->used_size)
		return ;
	add_new_char_vec(vec, elem);
	last_index = vec->used_size - 1;
	last_element = vec->elements[last_index];
	while (last_index > index)
	{
		vec->elements[last_index] = vec->elements[last_index - 1];
		last_index--;
	}
	vec->elements[index] = last_element;
}
