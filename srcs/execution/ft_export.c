/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:02:38 by hlimouni          #+#    #+#             */
/*   Updated: 2021/12/21 15:41:41 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	swap_strings(char **s1, char **s2)
{
	char *tmp;

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

int	invalid_option_error(char *arg)
{
	ft_putstr_fd("minishell: export: ", 2);
	write(2, arg, 2);
	ft_putstr_fd(": invalid option\n", 2);
	ft_putstr_fd("export: usage: export [-nf]", 2);
	ft_putstr_fd("[name[=value] ...] or export -p\n", 2);
	g_vars.last_err_num = 2;
	return (0);
}

int	invalid_identifier_error(char *arg)
{
	ft_putstr_fd("minishell: export: '", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	g_vars.last_err_num = 1;
	return (0);
}

int	is_arg_valid(char *arg)
{
	int	i;
	int	namelen;

	if (*arg == '-')
		return (invalid_option_error(arg));
	if (ft_isdigit(*arg))
		return (invalid_identifier_error(arg));
	i = 0;
	while (arg[i] && ft_strncmp(&arg[i], "+=", 2)
		&& arg[i] != '=')
		i++;
	namelen = i;
	i = 0;
	while (i < namelen && (ft_isalnum(arg[i]) || arg[i] == '_'))
		i++;
	if (i < namelen)
		return (invalid_identifier_error(arg));
	return (namelen);
}

/*
** * append_to_env_value
**
** *********************************************
** arg[valid_namelen] is the char '+'
** arg[valid_namelen + 1] is the char '='
** arg[valid_namelen + 2] is either '\0' or the
** 		beginning of the value to be appended
** *********************************************
*/

void	append_to_env_value(char *arg, int valid_namelen)
{
	int	i;
	char	*old_value;

	i = 0;
	while (i < g_vars.env_table.name.used_size)
	{
		if (!ft_strncmp(g_vars.env_table.name.elements[i], arg,
			valid_namelen))
		{
			old_value = g_vars.env_table.value.elements[i];
			if (!old_value)
				old_value = "";
			replace_element_at_index(&g_vars.env_table.value,
				ft_strjoin(old_value,
				// ft_strjoin(!g_vars.env_table.value.elements[i] ? "" :
				// g_vars.env_table.value.elements[i],
				&arg[valid_namelen + 2]), i);
				return ;
		}
		i++;
	}
	add_new_element(&g_vars.env_table.name, ft_substr(arg, 0, valid_namelen));
	add_new_element(&g_vars.env_table.value, ft_strdup(&arg[valid_namelen + 2]));
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
			valid_namelen))
		{
			if (arg[valid_namelen] == '=')
			{
				// free(g_vars.env_table.value.elements[i]);
				replace_element_at_index(&g_vars.env_table.value,
					ft_strdup(&arg[valid_namelen + 1]), i);
			}
			return ;
		}
		i++;
	}
	add_new_element(&g_vars.env_table.name,
		ft_substr(arg, 0, valid_namelen));
	if (arg[valid_namelen] == '=')
		// add_new_element(&g_vars.env_table.value, ft_substr(arg,
		// 	valid_namelen + 1, ft_strlen(arg) - valid_namelen));
		add_new_element(&g_vars.env_table.value,
		ft_strdup(&arg[valid_namelen + 1]));
	else
	{
		add_new_element(&g_vars.env_table.value, NULL);
		printf("null value added\n");
	}
}

void	update_env(t_ast *data)
{
	int	j;
	int	valid_namelen;

	j = 1;
	while (j < data->ARGC)
	{
		valid_namelen = is_arg_valid(data->ARGV[j]);
		if (valid_namelen)
		{
			if (!ft_strncmp(&data->ARGV[j][valid_namelen], "+=", 2))
				append_to_env_value(data->ARGV[j], valid_namelen);
			else
				add_valid_env_variable(data->ARGV[j], valid_namelen);
		}
		j++;
	}
}

void	copy_env(char ***env_names, char ***env_values)
{
	int	i;

	*env_names = malloc(sizeof(char *)
			* g_vars.env_table.name.used_size + 1);
	*env_values = malloc(sizeof(char *)
			* g_vars.env_table.value.used_size + 1);
	i = 0;
	while (i < g_vars.env_table.name.used_size)
	{
		(*env_names)[i] = g_vars.env_table.name.elements[i];
		(*env_values)[i] = g_vars.env_table.value.elements[i];
		i++;
	}
}

void	print_env(void)
{
	int	i;
	char	**env_names;
	char	**env_values;

	copy_env(&env_names, &env_values);
	sort_env(env_names, env_values, g_vars.env_table.name.used_size);
	i = 0;
	while (i < g_vars.env_table.name.used_size)
	{
		if (!env_values[i])
			printf("declare -x %s\n", env_names[i]);
		else if (env_names[i]
			&& ft_strcmp(env_names[i], "_"))
			printf("declare -x %s=\"%s\"\n", env_names[i], env_values[i]);
		i++;
	}
	free(env_names);
	free(env_values);
}


void	ft_export(t_ast *data)
{

	if (!data->ARGV[1])
		print_env();
	else
		update_env(data);
}