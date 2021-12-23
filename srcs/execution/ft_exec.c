/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:31:43 by hlimouni          #+#    #+#             */
/*   Updated: 2021/12/23 19:55:04 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

char	*ft_strjoin3(const char *s1, const char *s2, const char *s3)
{
	char	*temp;
	char	*ret;

	if (!s1 || !s2 || !s3)
		return (NULL);
	temp = ft_strjoin(s1, s2);
	if (!temp)
		return (NULL);
	ret = ft_strjoin(temp, s3);
	free(temp);
	return (ret);
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

void	ft_close_descriptors(t_ast *pipeline_seq)
{
	t_ast	*curr_smpl_cmd;
	t_ast	*curr_data;

	curr_smpl_cmd = pipeline_seq->node.pipe.dir.bottom;
	while (curr_smpl_cmd)
	{
		curr_data = curr_smpl_cmd->node.dir.bottom;
		if (curr_data->node.data.in_fd != 0)
			close(curr_data->node.data.in_fd);
		if (curr_data->node.data.out_fd != 1)
			close (curr_data->node.data.out_fd);
		curr_smpl_cmd = curr_smpl_cmd->node.dir.next;
	}
}

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

static void	ft_traverse_binaries(t_data *data, char **envp)
{
	int		i;
	char	*newpath;
	char	**paths;

	if (ft_execbuiltin(data) == -1)
	{
		execve(data->argv[0], data->argv, envp);
		if (get_env_value("PATH"))
		{
			paths = ft_split(get_env_value("PATH"), ':');
			i = 0;
			while (paths[i])
			{
				newpath = ft_strjoin3(paths[i], "/", data->argv[0]);
				execve(newpath, data->argv, envp);
				free(newpath);
				i++;
			}
			free_2d_array(&paths);
			ft_error(data->argv[0], "command not found");
		}
		else
			ft_error(data->argv[0], "No such file or directory");
	}
}

char	**get_env_array(void)
{
	int		i;
	char	*tmp_value;
	char	**name;
	char	**value;
	char	**env_array;

	i = 0;
	env_array = malloc((g_vars.env_table.name.used_size + 1) * sizeof(char *));
	name = g_vars.env_table.name.elements;
	value = g_vars.env_table.value.elements;
	while (name[i])
	{
		tmp_value = value[i];
		if (value[i] == NULL)
			tmp_value = "";
		env_array[i] = ft_strjoin3(name[i], "=", tmp_value);
		i++;
	}
	env_array[i] = NULL;
	return (env_array);
}

void	cmd_traverse(t_data *data, char **envp)
{
	if (data->argv[0][0] == '/' || !ft_strncmp(data->argv[0], "./", 2))
	{
		execve(data->argv[0], data->argv, envp);
		ft_error(data->argv[0], "No such file or directory");
	}
	else
		ft_traverse_binaries(data, envp);
}

void	ft_exec(t_data *data)
{
	char	**envp;

	if (!ft_isbuiltin(data->argv[0]) || data->pipes
		|| data->redirs)
	{
		if (dup2(*data->in_fd, 0) == -1 || dup2(*data->out_fd, 1) == -1)
		{
			perror("minishell");
			exit(1);
		}
		ft_close_descriptors(data->pip_seq);
		data->curr_data->node.data.out_fd = 1;
	}
	envp = get_env_array();
	cmd_traverse(data, envp);
	free_2d_array(&envp);
	if (data->pipes
		|| !ft_isbuiltin(data->argv[0]))
	{
		if (ft_isbuiltin(data->argv[0]))
			exit(g_vars.last_err_num);
		exit(127);
	}
}

int	ft_isbuiltin(char *builtin)
{
	if (ft_convert_builtin(builtin))
		return (1);
	return (0);
}
