/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_redirection_in_suitable_node.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:38:45 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/16 11:10:48 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "create_abstract_syntax_tree.h"

t_redirection	*create_single_redirection_node(char *type, char *file)
{
	t_redirection	*new_redirection_node;

	new_redirection_node = malloc(sizeof(t_redirection));
	new_redirection_node->type = ft_strdup(type);
	new_redirection_node->file = ft_strdup(file);
	new_redirection_node->next = NULL;
	return (new_redirection_node);
}

void	store_redir_in_suitable_node(t_ast_vars *vars, t_tokens **curr_token)
{
	t_redirection	**curr_redir_node;
	char			**type;
	char			**file;
	char			*here_doc;

	if (vars->state.data_node == NONE)
		get_suitable_nodes(vars->state, &vars->ast_ptrs);
	curr_redir_node = &((*vars->ast_ptrs.curr_data)->node.data.redirections);
	while (*curr_redir_node != NULL)
		curr_redir_node = &((*curr_redir_node)->next);
	type = &(*curr_token)->data;
	(*curr_token) = (*curr_token)->next;
	file = &(*curr_token)->data;
	if (ft_strcmp(*type, "<<") == 0)
	{
		here_doc = treat_heredocs(*file);
		free(*file);
		*file = here_doc;
	}
	*curr_redir_node = create_single_redirection_node(*type, *file);
}
