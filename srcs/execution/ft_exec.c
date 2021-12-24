/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 14:31:43 by hlimouni          #+#    #+#             */
/*   Updated: 2021/12/24 17:38:33 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

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

static char	**get_env_array(void)
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

static void	cmd_traverse(t_data *data, char **envp)
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
		|| data->curr_data->node.data.redirections)
	{
		if (dup2(*data->in_fd, 0) == -1 || dup2(*data->out_fd, 1) == -1)
		{
			perror("minishell");
			exit(1);
		}
		ft_close_descriptors(data->pip_seq);
	}
	envp = get_env_array();
	cmd_traverse(data, envp);
	free_2d_array(&envp);
	if (data->pipes || !ft_isbuiltin(data->argv[0]))
	{
		if (ft_isbuiltin(data->argv[0]))
			exit(g_vars.last_err_num);
		exit(127);
	}
}
