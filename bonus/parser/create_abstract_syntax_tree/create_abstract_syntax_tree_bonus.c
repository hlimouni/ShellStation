/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_abstract_syntax_tree_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:38:12 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:09:46 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_abstract_syntax_tree_bonus.h"

void	change_nodes_state(t_ast_vars *vars, t_type token)
{
	initialize_node_states(&vars->state);
	if (token == e_simple_word || token == less || token == great
		|| token == double_less || token == double_great)
	{
		vars->state.pipe_seq_node = EXIST;
		vars->state.simple_command_node = EXIST;
		vars->state.data_node = EXIST;
	}
	else if (token == e_pipe)
	{
		vars->state.pipe_seq_node = EXIST;
		vars->state.simple_command_node = EXIST;
		(*vars->ast_ptrs.curr_pipe_seq)->node.pipe.pipes_count++;
	}
	else if (token == e_semicolon)
		vars->state.pipe_seq_node = EXIST;
}

void	store_tokens_in_suitable_nodes(t_ast_vars *vars, t_tokens **curr_token)
{
	int	type;

	type = (*curr_token)->type;
	if (type == e_simple_word)
	{
		store_word_in_suitable_node(vars, (*curr_token)->data);
		change_nodes_state(vars, e_simple_word);
	}
	else if (type == less || type == great || type == double_great
		|| type == double_less)
		store_redir_in_suitable_node(vars, curr_token);
	change_nodes_state(vars, type);
}

void	create_abstract_syntax_tree(t_ast **ast, t_tokens *tokens)
{
	t_ast_vars	vars;
	t_tokens	*curr_token;

	initialize_ast_vars(&vars);
	*ast = create_single_node(e_cmdline_node);
	vars.ast_ptrs.cmd_line = ast;
	curr_token = tokens;
	while (curr_token)
	{
		store_tokens_in_suitable_nodes(&vars, &curr_token);
		curr_token = curr_token->next;
	}
}
