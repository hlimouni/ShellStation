/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_set_of_chars_at_index_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:44:24 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:06:52 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vectors_bonus.h"

void	add_set_of_chars_at_index(t_char_vec *vec, char *str, int index)
{
	int		i;

	if (index < 0 || index > vec->used_size || str == NULL)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		add_new_char_at_index(vec, str[i], index++);
		i++;
	}
}
