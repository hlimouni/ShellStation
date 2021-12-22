/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 14:45:13 by hlimouni          #+#    #+#             */
/*   Updated: 2021/12/22 20:40:38 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

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

void	ft_echo(t_ast *data)
{
	int	j;
	int	option_flag;

	j = 1;
	option_flag = is_option_set(data->ARGC, data->ARGV, &j);
	// printf("%d\n", option_flag);
	while (data->ARGV[j])
	{
		write(1, data->ARGV[j], ft_strlen(data->ARGV[j]));
		if (j < data->ARGC - 1)
			write(1, " ", 1);
		j++;
	}
	if (data->ARGV[1] == NULL || !option_flag)
		write(1, "\n", 1);
	g_vars.last_err_num = 0;
}

// int main(int ac, char **av)
// {
// 	t_ast data;

// 	data.ARGC = ac;
// 	data.ARGV = av;
// 	ft_echo(&data);
// 	return (0);
// }
		// if (!av[(*j)++][i])
		// {
		// 	flag = 1;
		// 	continue ;
		// }
		// else
		// 	break ;