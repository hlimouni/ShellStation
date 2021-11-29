/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 22:23:11 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/16 15:12:08 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digits_calc(int n)
{
	int		count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

void	store_num_in_str(char *result, unsigned int num, int size)
{
	result[size--] = '\0';
	while (num != 0)
	{
		result[size--] = (num % 10) + '0';
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	int				n_digits;
	int				size;
	char			*result;

	n_digits = digits_calc(n);
	if (n < 0)
		size = n_digits + 1;
	else
		size = n_digits;
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	if (n < 0)
		result[0] = '-';
	else if (n == 0)
		result[0] = '0';
	if (n < 0)
		num = n * -1;
	else
		num = n;
	store_num_in_str(result, num, size);
	return (result);
}
