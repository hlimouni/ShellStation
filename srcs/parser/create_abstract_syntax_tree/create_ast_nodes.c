/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_ast_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:38:26 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/24 10:49:09 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_abstract_syntax_tree.h"

t_ast	*create_single_node(t_tag tag)
{
	t_ast	*node;

	node = malloc(sizeof(t_ast));
	node->tag = tag;
	if (tag == e_data_node)
	{
		initialize_vec_content(&node->node.data.args_vec);
		node->node.data.redirections = NULL;
	}
	else if (tag == e_pipeline_node)
	{
		node->node.pipe.pipes_count = 0;
		node->node.pipe.dir.bottom = NULL;
		node->node.pipe.dir.next = NULL;
	}
	else
	{
		node->node.dir.bottom = NULL;
		node->node.dir.next = NULL;
	}
	return (node);
}

t_ast	**create_pipe_seq_node(t_ast **cmd_line, int dir)
{
	t_ast	**new_pipe_seq_node;

	if (dir == BOTTOM)
		new_pipe_seq_node = &((*cmd_line)->node.dir.bottom);
	else
		new_pipe_seq_node = &((*cmd_line)->node.pipe.dir.next);
	*new_pipe_seq_node = create_single_node(e_pipeline_node);
	return (new_pipe_seq_node);
}

t_ast	**create_smpl_cmd_node(t_ast **pipe_line_seq, int dir)
{
	t_ast	**new_cmd_node;

	if (dir == BOTTOM)
		new_cmd_node = &((*pipe_line_seq)->node.pipe.dir.bottom);
	else
		new_cmd_node = &((*pipe_line_seq)->node.dir.next);
	*new_cmd_node = create_single_node(e_simple_cmd_node);
	return (new_cmd_node);
}

t_ast	**create_data_node(t_ast **simple_cmd, int dir)
{
	t_ast	**new_data_node;

	if (dir == BOTTOM)
		new_data_node = &((*simple_cmd)->node.dir.bottom);
	else
		new_data_node = &((*simple_cmd)->node.dir.next);
	*new_data_node = create_single_node(e_data_node);
	return (new_data_node);
}
