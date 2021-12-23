/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:22:02 by hlimouni          #+#    #+#             */
/*   Updated: 2021/12/23 20:02:11 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

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

int	ft_strtod(char *str, long *num)
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

void	numeric_arg_error(char *arg)
{
	ft_putstr_fd("exit\nminishell: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
}

void	ft_exit(t_data *data)
{
	long	num;

	if (data->argc > 1)
	{
		if (!is_strint(data->argv[1]) || ft_strtod(data->argv[1], &num))
		{
			numeric_arg_error(data->argv[1]);
			exit(255);
		}
		else if (data->argc > 2)
		{
			ft_putstr_fd("exit\nminishell: exit: too many arguments\n", 2);
			g_vars.last_err_num = 1;
			return ;
		}
	}
	ft_putstr_fd("exit\n", 1);
	overwrite_history_file(&g_vars.rdl_vars);
	if (data->argv[1])
		exit(ft_atoi(data->argv[1]));
	exit(data->prev);
}
