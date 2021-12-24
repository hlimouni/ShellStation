/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:02:38 by hlimouni          #+#    #+#             */
/*   Updated: 2021/12/24 12:12:37 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

static void	update_env(t_data *data)
{
	int	j;
	int	valid_namelen;

	j = 1;
	while (j < data->argc)
	{
		valid_namelen = is_arg_valid(data->argv[j]);
		if (valid_namelen)
		{
			if (!ft_strncmp(&data->argv[j][valid_namelen], "+=", 2))
				append_to_env_value(data->argv[j], valid_namelen);
			else
				add_valid_env_variable(data->argv[j], valid_namelen);
		}
		j++;
	}
}

static void	copy_env(char ***env_names, char ***env_values)
{
	int	i;

	*env_names = malloc(sizeof(char *)
			* (g_vars.env_table.name.used_size + 1));
	*env_values = malloc(sizeof(char *)
			* (g_vars.env_table.value.used_size + 1));
	i = 0;
	while (i < g_vars.env_table.name.used_size)
	{
		(*env_names)[i] = g_vars.env_table.name.elements[i];
		(*env_values)[i] = g_vars.env_table.value.elements[i];
		i++;
	}
	(*env_names)[i] = g_vars.env_table.name.elements[i];
	(*env_values)[i] = g_vars.env_table.name.elements[i];
}

static void	print_env(void)
{
	int		i;
	char	**env_names;
	char	**env_values;

	copy_env(&env_names, &env_values);
	sort_env(env_names, env_values, g_vars.env_table.name.used_size);
	i = 0;
	while (i < g_vars.env_table.name.used_size)
	{
		if (!env_values[i])
			printf("declare -x %s\n", env_names[i]);
		else if (env_names[i] && env_values[i]
			&& ft_strcmp(env_names[i], "_"))
			printf("declare -x %s=\"%s\"\n", env_names[i], env_values[i]);
		i++;
	}
	free(env_names);
	free(env_values);
}

void	ft_export(t_data *data)
{
	if (!data->argv[1])
		print_env();
	else
		update_env(data);
}
