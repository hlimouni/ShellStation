/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 10:52:18 by iariss            #+#    #+#             */
/*   Updated: 2021/07/17 12:08:51 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"
#include "file_bonus.h"

void	remove_variable(char **a, int i)
{
	int	j;

	j = 0;
	while (j < g_vars.env_table.name.used_size)
	{
		if (!(ft_strcmp(a[i], g_vars.env_table.name.elements[j])))
		{
			g_vars.env_table.name.delete_element_at_index(
				&g_vars.env_table.name, j);
			g_vars.env_table.value.delete_element_at_index(
				&g_vars.env_table.value, j);
			return ;
		}
		j++;
	}
}

void	unset(t_ast *scn)
{
	t_unset_vars	u;

	u.i = 1;
	u.a = scn->node.data.args_vec.elements;
	while (u.i <= scn->node.data.args_vec.last_index)
	{
		u.x = 0;
		while (u.a[u.i][u.x] && u.a[u.i][u.x] != '=')
			u.x++;
		if (!ft_isalpha(u.a[u.i][0])
		|| (!ft_isalpha(u.a[u.i][ft_strlen(u.a[u.i]) - 1])
		&& !ft_isdigit(u.a[u.i][ft_strlen(u.a[u.i]) - 1])))
		{
			print_error("minishell: '");
			print_error(u.a[u.i]);
			print_error("': not a valid identifier\n");
			g_vars.last_err_num = 1;
		}
		else
			remove_variable(u.a, u.i);
		u.i++;
	}
}

void	add_one(t_varso *vars)
{
	int	i;

	i = 0;
	while (vars->export.env[i])
	{
		if (!(ft_strncmp(vars->export.env[i], "SHLVL", 5)))
		{
			vars->export.env[i][6] = vars->export.env[i][6] + 1;
		}
		i++;
	}
}
