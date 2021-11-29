/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 10:45:42 by iariss            #+#    #+#             */
/*   Updated: 2021/07/17 12:08:06 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_bonus.h"
#include "../minishell_bonus.h"

void	echo_n(int *j, int num_args, char **v, int *i)
{
	int	k;

	k = 0;
	while (*j < num_args && !ft_strncmp(v[*j], "-n", 2))
	{
		k = 2;
		while (v[*j][k])
		{
			if (v[*j][k] != 'n')
			{
				k = 0;
				break ;
			}
			k++;
		}
		if (!k)
			break ;
		(*j)++;
		*i = 1;
	}
}

void	echo(char **v)
{
	int	i;
	int	j;
	int	k;
	int	num_args;

	i = 0;
	j = 1;
	k = 2;
	num_args = check_echo(v);
	if (!num_args)
		return ;
	echo_n(&j, num_args, v, &i);
	while (v[j])
	{
		write(1, v[j], ft_strlen(v[j]));
		j++;
		if (v[j])
			write(1, " ", 1);
	}
	if (!i)
		write(1, "\n", 1);
	g_vars.last_err_num = 0;
}

int	check_echo(char **v)
{
	int	i;

	i = 0;
	while (v[i])
	{
		i++;
	}
	if (i == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	return (i);
}

char	*find_home(void)
{
	char	*home;
	char	cwd[PATH_MAX];
	int		i;
	int		slash;

	i = 0;
	slash = 2;
	getcwd(cwd, sizeof(cwd));
	while (cwd[i] && slash)
	{
		i++;
		if (cwd[i] == '/')
			slash--;
	}
	home = ft_substr(cwd, 0, i);
	return (home);
}
