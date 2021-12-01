/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:31:43 by hlimouni          #+#    #+#             */
/*   Updated: 2021/11/30 03:30:22 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

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

int	ft_execbuiltin(t_ast *data)
{
	int	ret;

	ret = ft_convert_builtin(data->ARGV[0]);
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
		ft_exit(data, g_vars.last_err_num);
	if (ret)
		return (0);
	return (-1);
}

// t_ast	*get_curr_smpl_cmd_node(t_ast *pipeline_seq)
// {
// 	static t_ast	*curr_smpl_cmd = NULL;
// 	static int		first = 1;

// 	if (pipeline_seq)
// 	{
// 		if (first == 1)
// 			curr_smpl_cmd = pipeline_seq->node.pipe.dir.bottom;
// 		else if (curr_smpl_cmd != NULL)
// 			curr_smpl_cmd = curr_smpl_cmd->node.dir.next;
// 		first++;
// 	}
// 	if (curr_smpl_cmd == NULL)
// 		first = 1;
// 	return (curr_smpl_cmd);
// }

void	ft_close_descriptors(t_ast *pipeline_seq)
{
	t_ast	*curr_smpl_cmd;
	t_ast	*curr_data;

	curr_smpl_cmd = pipeline_seq->node.pipe.dir.bottom;
	while (curr_smpl_cmd)
	{
		curr_data = curr_smpl_cmd->node.dir.bottom;
		if (curr_data->IN_FD != 0)
			close(curr_data->IN_FD);
		if (curr_data->OUT_FD != 1)
			close (curr_data->OUT_FD);
		curr_smpl_cmd = curr_smpl_cmd->node.dir.next;
	}
}

static void	ft_traverse_binaries(t_ast *data, char **envp)
{
	int		i;
	char	*newpath;
	char	**paths;
	char	*path_value;

	if (ft_execbuiltin(data) == -1)
	{
		execve(data->ARGV[0], data->ARGV, envp);
		path_value = get_value_of_env_name(g_vars.env_table, "PATH");
		if (path_value)
		{
			paths = ft_split(path_value, ':');
			i = 0;
			while (paths[i])
			{
				newpath = ft_strjoin3(paths[i], "/", data->ARGV[0]);
				execve(newpath, data->ARGV, envp);
				free(newpath);
				i++;
			}
			free_2d_array(&paths);
			ft_error(data->ARGV[0], "command not found");
		}
		else
			ft_error(data->ARGV[0], "No such file or directory");
	}
}

char	**get_env_array(void)
{
	int		i;
	int		size;
	char	**name;
	char	**value;
	char	**env_array;

	i = 0;
	size = g_vars.env_table.name.used_size + 1;
	env_array = malloc(size * sizeof(char *));
	name = g_vars.env_table.name.elements;
	value = g_vars.env_table.value.elements;
	while (name[i])
	{
		if (value[i] == NULL)
			value[i] = "";
		env_array[i] = ft_strjoin3(name[i], "=", value[i]);
		i++;
	}
	env_array[i] = NULL;
	return (env_array);
}


void	ft_exec(t_ast *data, t_ast *pipeline_seq)
{
	char	**envp;


	if (!ft_isbuiltin(data->ARGV[0]) || pipeline_seq->PIPES 
		|| pipeline_seq->node.data.redirections)
	{
		if (dup2(data->IN_FD, 0) == -1 || dup2(data->OUT_FD, 1) == -1)
		{
			perror("minishell");
			exit(1);
		}
		ft_close_descriptors(pipeline_seq);
			data->OUT_FD = 1;
	}
	envp = get_env_array();
	if (data->ARGV[0][0] == '/' || !ft_strncmp(data->ARGV[0], "./", 2))
	{
		execve(data->ARGV[0], data->ARGV, envp);
		ft_error(data->ARGV[0], "No such file or directory");
	}
	else
		ft_traverse_binaries(data, envp);
	free_2d_array(&envp);
	if (pipeline_seq->PIPES || !ft_isbuiltin(data->ARGV[0]))
	{
		if (ft_isbuiltin(data->ARGV[0]))
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

