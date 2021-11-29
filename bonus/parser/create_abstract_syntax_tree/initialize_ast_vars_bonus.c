/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_ast_vars_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:38:40 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:09:58 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_abstract_syntax_tree_bonus.h"

void	initialize_node_states(t_state *state)
{
	state->data_node = NONE;
	state->pipe_seq_node = NONE;
	state->simple_command_node = NONE;
}

void	initialize_ast_pointers(t_ast_ptrs *ast_ptrs)
{
	ast_ptrs->cmd_line = NULL;
	ast_ptrs->curr_data = NULL;
	ast_ptrs->curr_pipe_seq = NULL;
	ast_ptrs->curr_smpl_cmd = NULL;
}

void	initialize_ast_vars(t_ast_vars *vars)
{
	initialize_node_states(&vars->state);
	initialize_ast_pointers(&vars->ast_ptrs);
}
