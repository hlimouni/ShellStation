/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:09:29 by hlimouni          #+#    #+#             */
/*   Updated: 2021/12/15 12:16:41 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

void	add_env_variable(char *name, char *value)
{
	int	index;
	
	index = get_index_of_env_name(g_vars.env_table, name);
	if (index < 0)
	{
		add_new_element(&(g_vars.env_table.name), name);
		add_new_element(&(g_vars.env_table.value), value);
	}
	else
		replace_element_at_index(&(g_vars.env_table.value), value, index);
}

static int	change_dir(char *path)
{
	if (chdir(path) == 0)
	{
		add_env_variable("OLDPWD",
			ft_strdup(get_value_of_env_name(g_vars.env_table, "PWD")));
		add_env_variable("PWD", getcwd(NULL, 0));
	}
	else
	{
		ft_putstr_fd("minishell: cd ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		return (0);
	}
	return (1);
}

static char	*get_path_from_arg(char *arg)
{
	char	*path;

	if (!arg || !ft_strcmp(arg, "--") || !ft_strcmp(arg, "~"))
	{
		path = get_value_of_env_name(g_vars.env_table, "HOME");
		if (!path)
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
	}
	else if (!ft_strncmp(arg, "~/", 2))
	{
		path = get_value_of_env_name(g_vars.env_table, "HOME");
		if (!path)
		{
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
			return (path);
		}
		return (ft_strjoin(path, &arg[1]));
	}
	else if (!ft_strcmp(arg, "-"))
	{
		path = get_value_of_env_name(g_vars.env_table, "OLDPWD");
		if (!path)
			ft_putstr_fd("minishell: cd: OLDPWD not set\n", 2);
	}
	else
		path = arg;
	return (path);
}

void	ft_cd(t_ast *data)
{
	char *path;
	char	cwd[PATH_MAX];
	int	ret;

	path = get_path_from_arg(data->ARGV[1]);
	if (!path)
	{
		g_vars.last_err_num = 1;
		return ;
	}
	ret = change_dir(path);
	if (data->ARGV[1] && !ft_strncmp(data->ARGV[1], "~/", 2))
		free(path);
	if (ret == 0)
	{
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		g_vars.last_err_num = 1;
		return ;
	}
	if (data->ARGV[1] && !ft_strcmp(data->ARGV[1], "-"))
		printf("%s\n", getcwd(cwd, PATH_MAX));
}
