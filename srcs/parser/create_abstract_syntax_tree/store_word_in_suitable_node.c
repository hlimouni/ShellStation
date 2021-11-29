/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_word_in_suitable_node.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:38:51 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/20 14:52:42 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./create_abstract_syntax_tree.h"

void	store_word_in_suitable_node(t_ast_vars *vars, char *word)
{
	char		*element;
	t_str_vec	*args_vec;

	element = ft_strdup(word);
	get_suitable_nodes(vars->state, &vars->ast_ptrs);
	args_vec = &((*vars->ast_ptrs.curr_data)->node.data.args_vec);
	args_vec->add_new_element(args_vec, element);
}
