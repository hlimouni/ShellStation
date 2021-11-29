/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_len_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 13:52:41 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:12:31 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline_bonus.h"

int	get_max_len(t_str_vec files)
{
	int		i;
	int		len;
	int		curr_len;

	i = 0;
	len = 0;
	curr_len = 0;
	while (i < files.used_size)
	{
		curr_len = ft_strlen(files.elements[i]);
		if (curr_len > len)
			len = curr_len;
		i++;
	}
	return (len);
}
