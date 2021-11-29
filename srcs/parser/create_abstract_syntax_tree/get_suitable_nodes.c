/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_suitable_nodes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:38:31 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/15 17:32:06 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_abstract_syntax_tree.h"

void	get_suitable_pipe_seq_node(t_state state, t_ast_ptrs *ast)
{
	if (state.pipe_seq_node == NONE)
		ast->curr_pipe_seq = create_pipe_seq_node(ast->cmd_line, BOTTOM);
	else if (state.simple_command_node == NONE)
		ast->curr_pipe_seq = create_pipe_seq_node(ast->curr_pipe_seq, NEXT);
}

void	get_suitable_simple_cmd_node(t_state state, t_ast_ptrs *ast)
{
	if (state.simple_command_node == NONE)
		ast->curr_smpl_cmd = create_smpl_cmd_node(ast->curr_pipe_seq, BOTTOM);
	else if (state.data_node == NONE)
		ast->curr_smpl_cmd = create_smpl_cmd_node(ast->curr_smpl_cmd, NEXT);
}

void	get_suitable_data_node(t_state state, t_ast_ptrs *ast)
{
	if (state.data_node == NONE)
		ast->curr_data = create_data_node(ast->curr_smpl_cmd, BOTTOM);
	else if (state.data_node == EXIST)
		ast->curr_data = ast->curr_data;
}

void	get_suitable_nodes(t_state state, t_ast_ptrs *ast_ptrs)
{
	get_suitable_pipe_seq_node(state, ast_ptrs);
	get_suitable_simple_cmd_node(state, ast_ptrs);
	get_suitable_data_node(state, ast_ptrs);
}
