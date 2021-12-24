/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:49:33 by hlimouni          #+#    #+#             */
/*   Updated: 2021/12/24 12:49:55 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	init_pipe(t_ast *curr_data, t_ast *prev_data)
{
	int	fd[2];

	pipe(fd);
	if (prev_data->node.data.out_fd != 1)
		close(fd[1]);
	else
		prev_data->node.data.out_fd = fd[1];
	if (curr_data->node.data.in_fd != 0)
		close(fd[0]);
	else
		curr_data->node.data.in_fd = fd[0];
}
