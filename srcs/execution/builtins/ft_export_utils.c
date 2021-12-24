/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 10:02:48 by hlimouni          #+#    #+#             */
/*   Updated: 2021/12/24 12:12:29 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

static void	swap_strings(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	sort_env(char **name, char **value, int len)
{
	int		i;
	int		j;

	i = 0;
	while (i < len - 1)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (ft_strcmp(name[j], name[j + 1]) > 0)
			{
				swap_strings(&name[j], &name[j + 1]);
				swap_strings(&value[j], &value[j + 1]);
			}
			j++;
		}
		i++;
	}
}

/*
** * append_to_env_value
** *
** * *********************************************
** * arg[valid_namelen] is the char '+'
** * arg[valid_namelen + 1] is the char '='
** * arg[valid_namelen + 2] is either '\0' or the
** * 		beginning of the value to be appended
** * *********************************************
*/

void	append_to_env_value(char *arg, int valid_namelen)
{
	int		i;
	char	*old_value;

	i = 0;
	while (i < g_vars.env_table.name.used_size)
	{
		if (!ft_strncmp(g_vars.env_table.name.elements[i], arg,
				valid_namelen)
			&& !g_vars.env_table.name.elements[i][valid_namelen])
		{
			old_value = g_vars.env_table.value.elements[i];
			if (!old_value)
				old_value = "";
			replace_element_at_index(&g_vars.env_table.value,
				ft_strjoin(old_value,
					&arg[valid_namelen + 2]), i);
			return ;
		}
		i++;
	}
	add_new_element(&g_vars.env_table.name, ft_substr(arg, 0, valid_namelen));
	add_new_element(&g_vars.env_table.value,
		ft_strdup(&arg[valid_namelen + 2]));
}

/*
**	the arg[valid_namelen] char is either '=' or '\0'
*/

void	add_valid_env_variable(char *arg, int valid_namelen)
{
	int	i;

	i = 0;
	while (i < g_vars.env_table.name.used_size)
	{
		if (!ft_strncmp(g_vars.env_table.name.elements[i], arg,
				valid_namelen)
			&& !g_vars.env_table.name.elements[i][valid_namelen])
		{
			if (arg[valid_namelen] == '=')
				replace_element_at_index(&g_vars.env_table.value,
					ft_strdup(&arg[valid_namelen + 1]), i);
			return ;
		}
		i++;
	}
	add_new_element(&g_vars.env_table.name,
		ft_substr(arg, 0, valid_namelen));
	if (arg[valid_namelen] == '=')
		add_new_element(&g_vars.env_table.value,
			ft_strdup(&arg[valid_namelen + 1]));
	else
		add_new_element(&g_vars.env_table.value, NULL);
}
