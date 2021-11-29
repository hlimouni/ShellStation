/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_cmd_exist.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:48:57 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/16 11:12:36 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline.h"

static int	check_if_cmd_is_builtin(char *cmd)
{
	if (ft_strcmp(cmd, "export") == 0)
		return (true);
	else if (ft_strcmp(cmd, "echo") == 0)
		return (true);
	else if (ft_strcmp(cmd, "env") == 0)
		return (true);
	else if (ft_strcmp(cmd, "unset") == 0)
		return (true);
	else if (ft_strcmp(cmd, "cd") == 0)
		return (true);
	else if (ft_strcmp(cmd, "pwd") == 0)
		return (true);
	else if (ft_strcmp(cmd, "exit") == 0)
		return (true);
	return (false);
}

static char	*join_cmd_with_path(char *path, char *cmd)
{
	char		*tmp;
	char		*file;

	tmp = ft_strjoin(path, "/");
	file = ft_strjoin(tmp, cmd);
	free(tmp);
	return (file);
}

static int	check_if_cmd_exists_in_given_paths(char *cmd, char *path_env)
{
	int			i;
	char		*file;
	char		*path;
	int			start;
	int			is_exist;

	i = 0;
	start = 0;
	is_exist = NONE;
	while (path_env[i] != '\0' && is_exist == NONE)
	{
		if (path_env[i] == ':')
		{
			path = ft_substr(path_env, start, i - start);
			file = join_cmd_with_path(path, cmd);
			if (check_if_file_exist(file) == EXIST)
				is_exist = TRUE;
			free(file);
			free(path);
			start = i + 1;
		}
		i++;
	}
	return (is_exist);
}

int	check_if_cmd_exist(char *cmd)
{
	char		*path_env;
	int			does_it_exist;

	does_it_exist = NONE;
	path_env = get_value_of_env_name(g_vars.env_table, "PATH");
	if (path_env != NULL)
		does_it_exist = check_if_cmd_exists_in_given_paths(cmd, path_env);
	if (does_it_exist == EXIST)
		return (EXIST);
	if (check_if_cmd_is_builtin(cmd) == true)
		return (EXIST);
	return (NONE);
}
