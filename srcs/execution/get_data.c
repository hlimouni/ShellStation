/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:53:34 by hlimouni          #+#    #+#             */
/*   Updated: 2021/12/24 12:53:43 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

t_data	get_data(t_ast *smpl_cmd, t_ast *pipseq)
{
	t_ast	*curr_data;
	t_data	data;

	curr_data = smpl_cmd->node.dir.bottom;
	data.prev = smpl_cmd->node.data.prev_errnum;
	data.argv = curr_data->node.data.args_vec.elements;
	data.argc = curr_data->node.data.args_vec.used_size;
	data.pipes = pipseq->node.pipe.pipes_count;
	data.pids = pipseq->node.pipe.pids;
	data.out_fd = &curr_data->node.data.out_fd;
	data.in_fd = &curr_data->node.data.in_fd;
	data.redirs = pipseq->node.data.redirections;
	data.curr_data = curr_data;
	data.pip_seq = pipseq;
	return (data);
}
