/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 10:48:41 by iariss            #+#    #+#             */
/*   Updated: 2021/11/03 09:34:52 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_bonus.h"
#include "../minishell_bonus.h"

void	add_to_vars(char *add, int x)
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < g_vars.env_table.name.used_size)
	{
		tmp = ft_substr(add, 0, x);
		if (!(ft_strcmp(g_vars.env_table.name.elements[i],
					tmp)))
		{
			if (!g_vars.env_table.value.elements[i])
				g_vars.env_table.value.elements[i] = ft_strdup("");
			g_vars.env_table.value.replace_element_at_index(
				&g_vars.env_table.value,
			ft_strjoin(g_vars.env_table.value.elements[i], add + x + 2), i);
			free(tmp);
			return ;
		}
		free(tmp);
		i++;
	}
	g_vars.env_table.name.add_new_element(&g_vars.env_table.name,
	ft_substr(add, 0, x));
	g_vars.env_table.value.add_new_element(&g_vars.env_table.value,
	ft_strdup(add + x + 2));
}

void	sort_loop(t_expo_vars *exp, t_varso *vars)
{
	exp->j = exp->i;
	exp->smallest = vars->export.names[exp->i];
	exp->k = exp->i;
	while (exp->j < g_vars.env_table.name.used_size)
	{
		if (ft_strcmp(vars->export.names[exp->j], exp->smallest) < 0)
		{
			exp->smallest = vars->export.names[exp->j];
			exp->k = exp->j;
		}
		exp->j++;
	}
	swap_values(&vars->export.names[exp->i], &vars->export.names[exp->k]);
	swap_values(&vars->export.values[exp->i], &vars->export.values[exp->k]);
	exp->i++;
}

void	sort_expo(t_varso *vars)
{
	t_expo_vars	exp;

	exp.i = 0;
	exp.smallest = g_vars.env_table.name.elements[0];
	while (exp.i < g_vars.env_table.name.used_size)
		sort_loop(&exp, vars);
	exp.i = 0;
	while (exp.i < g_vars.env_table.name.used_size)
	{
		exp.j = 0;
		while (vars->export.names[exp.i][exp.j] &&
				vars->export.names[exp.i][exp.j] != '=')
			exp.j++;
		print_expo(vars, &exp);
		exp.i++;
	}
	exp.i = 0;
	while (vars->export.names[exp.i])
		free(vars->export.names[exp.i++]);
	exp.i = 0;
	while (vars->export.values[exp.i])
		free(vars->export.values[exp.i++]);
}

void	empty_expo(t_varso *vars)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < g_vars.env_table.name.used_size)
	{
		vars->export.names[i] = ft_strdup(g_vars.env_table.name.elements[i]);
		if (!g_vars.env_table.value.elements[i])
			vars->export.values[i] = ft_strdup("2");
		else
			vars->export.values[i] = ft_strjoin("1",
					g_vars.env_table.value.elements[i]);
		i++;
	}
	vars->export.names[i] = NULL;
	vars->export.values[i] = NULL;
	sort_expo(vars);
}

void	export(char **args, t_varso *vars, t_ast *sim_cmd_nd)
{
	int	i;
	int	lp;

	i = 0;
	lp = 1;
	vars->export.names = malloc(sizeof(char *)
			* g_vars.env_table.name.used_size + 1);
	vars->export.values = malloc(sizeof(char *)
			* g_vars.env_table.value.used_size + 1);
	if (g_vars.env_table.name.used_size)
	{
		if (!args[1])
		{
			empty_expo(vars);
			free(vars->export.names);
			free(vars->export.values);
			return ;
		}
		else
			export_add_vars(sim_cmd_nd, args);
	}
	else if (args[1])
		export_add_vars(sim_cmd_nd, args);
	free(vars->export.names);
	free(vars->export.values);
}
