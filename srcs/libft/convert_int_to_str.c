/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int_to_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:29:41 by iltafah           #+#    #+#             */
/*   Updated: 2021/12/24 13:56:37 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

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
