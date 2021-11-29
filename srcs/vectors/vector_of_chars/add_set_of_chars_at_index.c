/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_set_of_chars_at_index.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:44:24 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/13 19:44:26 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vectors.h"

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
