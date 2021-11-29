/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_and_free_vec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:44:42 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/13 19:44:43 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vectors.h"

void	realloc_vector_of_char_vec(t_vchar_vec *vec)
{
	int			i;
	t_char_vec	*new_table;

	i = -1;
	new_table = malloc(sizeof(t_char_vec) * vec->size);
	while (++i < vec->used_size)
		new_table[i] = vec->elements[i];
	free(vec->elements);
	vec->elements = new_table;
}

void	char_vec_vector_free(t_vchar_vec *vec)
{
	int		i;

	i = 0;
	while (i < vec->used_size)
		free(vec->elements[i++].elements);
	free(vec->elements);
}
