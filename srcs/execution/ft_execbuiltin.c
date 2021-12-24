/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execbuiltin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 10:32:45 by hlimouni          #+#    #+#             */
/*   Updated: 2021/12/24 13:54:11 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

char	*get_env_value(char *name)
{
	int		i;

	i = 0;
	while (g_vars.env_table.name.elements[i] != NULL)
	{
		if (ft_strcmp(g_vars.env_table.name.elements[i], name) == 0)
			return (g_vars.env_table.value.elements[i]);
		i++;
	}
	return (NULL);
}

int	ft_error(char *name, char *desc)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(desc, 2);
	ft_putstr_fd("\n", 2);
	return (1);
}

int	ft_convert_builtin(char *builtin)
{
	if (!ft_strcmp(builtin, "echo"))
		return (__echo);
	else if (!ft_strcmp(builtin, "cd"))
		return (__cd);
	else if (!ft_strcmp(builtin, "pwd"))
		return (__pwd);
	else if (!ft_strcmp(builtin, "export"))
		return (__export);
	else if (!ft_strcmp(builtin, "unset"))
		return (__unset);
	else if (!ft_strcmp(builtin, "env"))
		return (__env);
	else if (!ft_strcmp(builtin, "exit"))
		return (__exit);
	return (0);
}

int	ft_execbuiltin(t_data *data)
{
	int	ret;

	ret = ft_convert_builtin(data->argv[0]);
	if (ret == __echo)
		ft_echo(data);
	else if (ret == __cd)
		ft_cd(data);
	else if (ret == __pwd)
		ft_pwd();
	else if (ret == __export)
		ft_export(data);
	else if (ret == __unset)
		ft_unset(data);
	else if (ret == __env)
		ft_env();
	else if (ret == __exit)
		ft_exit(data);
	if (ret)
		return (0);
	return (-1);
}

int	ft_isbuiltin(char *builtin)
{
	if (ft_convert_builtin(builtin))
		return (1);
	return (0);
}
