/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_utf8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:42:19 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/13 20:26:18 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int	ft_strlen_utf8(char *str)
{
	int	byte;
	int	count;

	byte = 0;
	count = 0;
	while (str[byte])
	{
		if ((str[byte] & 0xc0) != 0x80)
			count++;
		byte++;
	}
	return (count);
}
