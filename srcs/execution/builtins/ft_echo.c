/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:45:13 by hlimouni          #+#    #+#             */
/*   Updated: 2021/12/24 12:11:53 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

int	is_option_set(int ac, char **av, int *j)
{
	int	i;
	int	flag;

	flag = 0;
	while (*j < ac && !ft_strncmp(av[*j], "-n", 2))
	{
		i = 2;
		while (av[*j][i] == 'n')
			i++;
		if (av[*j][i])
			break ;
		flag = 1;
		(*j)++;
	}
	return (flag);
}

void	ft_echo(t_data *data)
{
	int	j;
	int	option_flag;

	j = 1;
	option_flag = is_option_set(data->argc,
			data->argv, &j);
	while (data->argv[j])
	{
		write(1, data->argv[j],
			ft_strlen(data->argv[j]));
		if (j < data->argc - 1)
			write(1, " ", 1);
		j++;
	}
	if (data->argv[1] == NULL || !option_flag)
		write(1, "\n", 1);
	g_vars.last_err_num = 0;
}
