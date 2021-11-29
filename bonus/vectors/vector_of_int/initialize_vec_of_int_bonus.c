/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_vec_of_int_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:43:40 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:06:28 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vectors_bonus.h"

void	initialize_vec_of_int(t_int_vec *vec)
{
	vec->size = 2;
	vec->used_size = 0;
	vec->last_index = 0;
	vec->elements = malloc(sizeof(int) * vec->size);
	vec->add_new_element = add_new_int;
	vec->add_new_element_at_index = add_new_int_at_index;
	vec->replace_element_at_index = replace_int_at_index;
	vec->delete_element_at_index = delete_int_at_index;
	vec->push_element = push_int;
	vec->pop_element = pop_int;
	vec->free = int_vector_free;
}
