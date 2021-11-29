/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_and_free_vec_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:42:50 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:06:06 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vectors_bonus.h"

void	realloc_vector(t_str_vec *vec)
{
	int		i;
	char	**new_table;

	i = -1;
	new_table = malloc(sizeof(char *) * (vec->size + 1));
	while (++i < vec->used_size)
		new_table[i] = vec->elements[i];
	new_table[i] = NULL;
	free(vec->elements);
	vec->elements = new_table;
}

void	vector_free(t_str_vec *vec)
{
	int		i;

	i = 0;
	while (i < vec->used_size)
	{
		free(vec->elements[i]);
		vec->elements[i++] = NULL;
	}
	free(vec->elements);
	vec->elements = NULL;
}
