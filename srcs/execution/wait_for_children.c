/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_for_children.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:25:31 by hlimouni          #+#    #+#             */
/*   Updated: 2021/12/24 12:25:54 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

t_ast	*ft_find_command(int pid, t_ast *pipeline_seq)
{
	int		i;
	t_ast	*curr_smpl_cmd;

	curr_smpl_cmd = pipeline_seq->node.pipe.dir.bottom;
	i = 0;
	while (curr_smpl_cmd)
	{
		if (pipeline_seq->node.pipe.pids[i] == pid)
			return (curr_smpl_cmd->node.dir.bottom);
		i++;
		curr_smpl_cmd = curr_smpl_cmd->node.dir.next;
	}
	return (NULL);
}

static void	ft_update_status(int terminated_pid, int status,
				t_ast	*pipeline_seq)
{
	t_ast	*curr_data;

	if (terminated_pid == pipeline_seq
		->node.pipe.pids[pipeline_seq->node.pipe.pipes_count])
	{
		if (!WTERMSIG(status))
			g_vars.last_err_num = WEXITSTATUS(status);
		else
			g_vars.last_err_num = WTERMSIG(status) + 128;
	}
	curr_data = ft_find_command(terminated_pid, pipeline_seq);
	if (curr_data)
	{
		if (curr_data->node.data.out_fd != 1)
			close(curr_data->node.data.out_fd);
		if (curr_data->node.data.in_fd != 0)
			close(curr_data->node.data.in_fd);
	}
}

void	wait_for_children(t_ast *pipeline_seq)
{
	int		i;
	int		status;

	i = 0;
	while (i <= pipeline_seq->node.pipe.pipes_count)
	{
		ft_update_status(wait(&status), status, pipeline_seq);
		i++;
	}
}
