/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 17:22:02 by hlimouni          #+#    #+#             */
/*   Updated: 2021/12/24 12:12:11 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

static void	numeric_arg_error(char *arg)
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
		if (!is_strint(data->argv[1]) || ft_strto_long(data->argv[1], &num))
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
