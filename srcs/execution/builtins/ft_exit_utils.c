/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:50:05 by hlimouni          #+#    #+#             */
/*   Updated: 2021/12/24 12:12:06 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

int	ft_isspace(int c)
{
	return ((c == '\n' || c == '\t' || c == ' '
			|| c == '\v' || c == '\f' || c == '\r'));
}

int	is_strint(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	if ((str[i] == '-' || str[i] == '+') && ft_strlen(str) > 1)
		i++;
	while (ft_isdigit(str[i++]))
		if (ft_strlen(str) == i)
			return (i);
	return (0);
}

int	ft_getstr_sign(char *str, int *index)
{
	int		sign;

	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		(*index)++;
	}
	if (*str == '+')
	{
		sign = 1;
		(*index)++;
	}
	return (sign);
}

int	ft_strto_long(char *str, long *num)
{
	int		i;
	int		sn;
	long	res;
	long	tmp;

	i = 0;
	res = 0;
	while (ft_isspace(str[i]))
		i++;
	sn = ft_getstr_sign(str + i, &i);
	while (ft_isdigit(str[i]))
	{
		tmp = res;
		res = res * 10 + (str[i] - '0') * sn;
		if ((sn == 1 && tmp > res) || (sn == -1 && tmp < res))
			return (1);
		i++;
	}
	*num = res;
	return (0);
}
