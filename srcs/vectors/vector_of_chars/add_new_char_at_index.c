/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_char_at_index.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:44:36 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/19 21:48:19 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vectors.h"

void	add_new_char_at_index(t_char_vec *vec, char c, int index)
{
	char	last_element;
	int		i;

	if (index < 0 || index > vec->size)
		return ;
	add_new_char(vec, c);
	last_element = vec->elements[vec->last_index];
	i = vec->last_index;
	while (i > index)
	{
		vec->elements[i] = vec->elements[i - 1];
		i--;
	}
	vec->elements[index] = last_element;
}
