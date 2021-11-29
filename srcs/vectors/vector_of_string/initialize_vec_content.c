/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_vec_content.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:42:55 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/20 15:29:09 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vectors.h"

void	initialize_vec_content(t_str_vec *vec)
{
	vec->size = 2;
	vec->used_size = 0;
	vec->last_index = 0;
	vec->elements = malloc(sizeof(char *) * (vec->size + 1));
	vec->elements[0] = NULL;
	vec->add_new_element = add_new_element;
	vec->add_new_element_at_index = add_new_element_at_index;
	vec->replace_element_at_index = replace_element_at_index;
	vec->delete_element_at_index = delete_element_at_index;
	vec->free = vector_free;
}
