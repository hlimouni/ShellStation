/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export3_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:49:58 by iariss            #+#    #+#             */
/*   Updated: 2021/07/17 12:08:34 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_bonus.h"

int	check_args2(int lp, char **arg)
{
	int	x;

	x = 0;
	while (arg[lp][x] && arg[lp][x] != '=' && ft_strncmp(arg[lp] + x, "+=", 2))
		x++;
	if (((!ft_isalpha(arg[lp][0])
			|| (!ft_isalnum(arg[lp][x - 1])
			&& arg[lp][x - 1] != '=')))
			&& arg[lp][0] != '_' && arg[lp][x - 1] != '_')
	{
		print_error("minishell: export: '");
		print_error(arg[lp]);
		print_error("': not a valid identifier\n");
		g_vars.last_err_num = 1;
		return (0);
	}
	return (1);
}

int	check_middle(char *s)
{
	int	i;

	i = 1;
	while (s[i] && s[i] != '=' && i < (int)ft_strlen(s)
		&& ft_strncmp(s + i, "+=", 2))
	{
		if (!ft_isalnum(s[i]) && s[i] != '_')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_args(char **a, int lp)
{
	t_expo_vars	cv;

	cv.i = 0;
	if (a[lp][0] == '-')
	{
		cv.subbed = ft_substr(a[lp], 0, 2);
		print_error("minishell: export: ");
		print_error(cv.subbed);
		print_error(": invalid option\nexport: usage: ");
		print_error("export [-nf] [name[=value] ...] or export -p\n");
		g_vars.last_err_num = 2;
		free(cv.subbed);
	}
	else if (ft_isdigit(a[lp][0]) || !check_middle(a[lp]))
	{
		print_error("minishell: export: `");
		print_error(a[lp]);
		print_error("': not a valid identifier\n");
		g_vars.last_err_num = 1;
		return (0);
	}
	else
		return (check_args2(lp, a));
	return (1);
}

void	print_error(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
}
