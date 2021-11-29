/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_char_at_index_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:44:03 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:06:39 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vectors_bonus.h"

void	replace_char_at_index(t_char_vec *vec, char c, int index)
{
	if (index < 0 || index > vec->last_index)
		return ;
	vec->elements[index] = c;
}
