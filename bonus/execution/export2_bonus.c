/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <iariss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 10:44:47 by iariss            #+#    #+#             */
/*   Updated: 2021/07/17 13:24:52 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_bonus.h"

void	swap_values(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	normal_expo(char **args, int lp, int x)
{
	int	len;

	len = ft_strlen(args[lp]);
	g_vars.env_table.name.add_new_element(&g_vars.env_table.name,
	ft_substr(args[lp], 0, x));
	if (len == x && !args[lp][x] && args[lp][x - 1] != '=')
	{
		g_vars.env_table.value.add_new_element(
			&g_vars.env_table.value, NULL);
	}
	else
	{
		g_vars.env_table.value.add_new_element(&g_vars.env_table.value,
		ft_substr(args[lp], x + 1, len - x));
	}
}

void	export_add(char **args, int lp, int x)
{
	int		i;
	int		in;
	char	*tmp;

	i = 0;
	in = 0;
	while (i < g_vars.env_table.name.used_size)
	{
		tmp = ft_substr(args[lp], 0, x);
		if (!ft_strcmp(g_vars.env_table.name.elements[i], tmp)
			&& args[lp][x])
		{
			g_vars.env_table.value.replace_element_at_index(
			&g_vars.env_table.value, ft_strdup(args[lp] + x + 1), i);
			in = 1;
		}
		else if (!ft_strcmp(g_vars.env_table.name.elements[i],
				tmp) && !args[lp][x])
			in = 1;
		free(tmp);
		i++;
	}
	if (!in)
		normal_expo(args, lp, x);
}

void	print_expo(t_varso *vars, t_expo_vars *exp)
{
	if (ft_strlen(vars->export.values[exp->i]) == 1
		&& vars->export.values[exp->i][0] == '2')
	{
		printf("declare -x %s\n", vars->export.names[exp->i]);
	}
	else if (vars->export.names[exp->i]
		&& ft_strcmp(vars->export.names[exp->i], "_"))
	{
		printf("declare -x %s=\"%s\"\n", vars->export.names[exp->i],
			vars->export.values[exp->i] + 1);
	}
}

void	export_add_vars(t_ast *scn, char **args)
{
	int	lp;
	int	x;

	lp = 1;
	while (lp <= scn->node.data.args_vec.last_index)
	{
		x = 0;
		while (args[lp][x] && args[lp][x] != '=' &&
		ft_strncmp(args[lp] + x, "+=", 2))
			x++;
		if (check_args(args, lp))
		{	
			if (!ft_strncmp(args[lp] + x, "+=", 2))
				add_to_vars(args[lp], x);
			else
				export_add(args, lp, x);
		}
		lp++;
	}
}
