/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_vec_of_char_vec_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:44:46 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:07:19 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vectors_bonus.h"

void	initialize_vec_of_char_vec(t_vchar_vec *vec)
{
	vec->size = 2;
	vec->used_size = 0;
	vec->last_index = 0;
	vec->elements = malloc(sizeof(t_char_vec) * (vec->size));
	vec->add_new_element = add_new_char_vec;
	vec->add_new_element_at_index = add_new_char_vec_at_index;
	vec->delete_element_at_index = delete_char_vec_at_index;
	vec->delete_last_element = delete_last_char_vec;
	vec->free = char_vec_vector_free;
}
