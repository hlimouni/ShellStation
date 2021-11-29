/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_element_at_index.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:42:45 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/06 13:39:57 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vectors.h"

void	replace_element_at_index(t_str_vec *vec, char *element, int index)
{
	if (index < 0 || index > vec->used_size - 1)
		return ;
	free(vec->elements[index]);
	vec->elements[index] = element;
}
