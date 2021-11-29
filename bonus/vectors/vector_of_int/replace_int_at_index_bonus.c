/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_int_at_index_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:43:19 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:06:19 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vectors_bonus.h"

void	replace_int_at_index(t_int_vec *vec, int num, int index)
{
	if (index < 0 || index > vec->last_index)
		return ;
	vec->elements[index] = num;
}
