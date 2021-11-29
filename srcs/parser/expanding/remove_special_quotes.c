/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_special_quotes.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:39:17 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/15 13:50:58 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./expanding.h"

int	is_it_special_quotes(char c)
{
	return (c == SP_BACKSLASH
		|| c == SP_DOUBLE_QUOTES
		|| c == SP_SINGLE_QUOTES);
}

void	remove_special_quotes(char **str_addr)
{
	int			i;
	char		*old_str;
	t_char_vec	new_str;

	i = 0;
	old_str = *str_addr;
	initialize_vec_of_char(&new_str);
	while (old_str[i] != '\0')
	{
		if (is_it_special_quotes(old_str[i]) == FALSE)
			new_str.add_new_element(&new_str, old_str[i]);
		i++;
	}
	free(*str_addr);
	*str_addr = new_str.elements;
}
