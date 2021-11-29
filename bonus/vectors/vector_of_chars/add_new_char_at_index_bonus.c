/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_char_at_index_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:44:36 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:07:00 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vectors_bonus.h"

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
