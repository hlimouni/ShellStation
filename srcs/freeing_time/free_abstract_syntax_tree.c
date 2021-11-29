/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_abstract_syntax_tree.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:45:47 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/14 21:43:13 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./freeing_time.h"

void	free_redirection_list(t_redirection **redirection_list)
{
	t_redirection	*curr_redir_node;
	t_redirection	*next_redir_node;

	curr_redir_node = *redirection_list;
	while (curr_redir_node)
	{
		next_redir_node = curr_redir_node->next;
		free(curr_redir_node->file);
		free(curr_redir_node->type);
		free(curr_redir_node);
		curr_redir_node = next_redir_node;
	}
	*redirection_list = NULL;
}

void	free_args_vec(t_str_vec *args_vec)
{
	args_vec->free(args_vec);
}

void	free_data_node_content(t_data_content *node_data)
{
	free_args_vec(&node_data->args_vec);
	free_redirection_list(&node_data->redirections);
}

void	free_abstract_syntax_tree(t_ast **ast)
{
	if (*ast == NULL)
		return ;
	if ((*ast)->tag == e_cmdline_node || (*ast)->tag == e_simple_cmd_node)
	{
		free_abstract_syntax_tree(&(*ast)->node.dir.bottom);
		free_abstract_syntax_tree(&(*ast)->node.dir.next);
	}
	else if ((*ast)->tag == e_pipeline_node)
	{
		free_abstract_syntax_tree(&(*ast)->node.pipe.dir.bottom);
		free_abstract_syntax_tree(&(*ast)->node.pipe.dir.next);
	}
	else if ((*ast)->tag == e_data_node)
		free_data_node_content(&(*ast)->node.data);
	free(*ast);
	*ast = NULL;
}
