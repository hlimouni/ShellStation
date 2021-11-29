/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 10:42:54 by iariss            #+#    #+#             */
/*   Updated: 2021/07/17 12:07:47 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_bonus.h"
#include "../minishell_bonus.h"

void	cd_3(char **path)
{
	char	cwd[PATH_MAX];

	if (chdir(*path) != 0 && getcwd(cwd, sizeof(cwd)))
	{
		print_error("chdir failed\n");
		g_vars.last_err_num = 1;
	}
	else if (!getcwd(cwd, sizeof(cwd)))
	{
		if (!g_vars.last_err_num)
		{
			print_error("cd: error retrieving current directory: ");
			print_error("getcwd: cannot access parent directories");
			print_error(": No such file or directory\n");
		}
		g_vars.last_err_num = 1;
	}
}

void	cd_2(char **path, int *f)
{
	char		cwd[PATH_MAX];
	struct stat	buffer;

	if (stat(*path, &buffer) == -1)
	{
		print_error("minishell: cd: ");
		print_error(*path);
		print_error(": No such file or directory\n");
		g_vars.last_err_num = 1;
	}
	else
		cd_3(path);
	getcwd(cwd, sizeof(cwd));
	if (*f)
		free(*path);
	*path = ft_strdup(cwd);
	change_value("PWD", *path);
	free(*path);
}

void	cd(char **args, t_varso *vars)
{
	char	*path;
	char	*home;
	char	cwd[PATH_MAX];
	int		f;

	f = 0;
	home = find_env("HOME");
	if (!args[1])
	{
		if (home)
			path = home;
		else
		{
			print_error("minishell: cd: HOME not set\n");
			g_vars.last_err_num = 1;
			return ;
		}
	}
	else
		path = args[1];
	check_path(&path, &f);
	getcwd(cwd, sizeof(cwd));
	vars->prev_path = cwd;
	change_value("OLDPWD", vars->prev_path);
	cd_2(&path, &f);
}

void	check_path(char **path, int *f)
{
	char	*new;

	new = find_home();
	if (*path[0] == '~' || !(ft_strcmp(*path, "~/")))
	{
		if ((ft_strlen(*path) == 1 && *path[0] == '~') || ft_strlen(*path) == 2)
		{
			*path = ft_strdup(new);
			*f = 1;
		}
		else
		{
			*path = ft_strjoin(new, *path + 1);
			*f = 1;
		}
		free(new);
		return ;
	}
	free(new);
	return ;
}

void	change_value(char *name, char *new_value)
{
	int	i;

	i = 0;
	while (i < g_vars.env_table.name.used_size)
	{
		if (!(ft_strcmp(g_vars.env_table.name.elements[i]
					, name)))
		{
			g_vars.env_table.value.replace_element_at_index(
				&g_vars.env_table.value, ft_strdup(new_value), i);
			return ;
		}
		i++;
	}
}
