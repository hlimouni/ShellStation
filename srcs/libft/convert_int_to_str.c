/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int_to_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:29:41 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/06 20:33:34 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <stdio.h>
char	*convert_int_to_str(int num)
{
	char	*str;
	int		digits;
	int		len;

	digits = count_digits(num);
	len = digits + 1;
	str = malloc(sizeof(char) * len);
	str[digits] = '\0';
	while (digits-- > 0)
	{
		str[digits] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
