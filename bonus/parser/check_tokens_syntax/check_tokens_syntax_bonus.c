/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tokens_syntax_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:35:15 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:09:24 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_tokens_syntax_bonus.h"

void	remember_last_token(t_vars *vars, t_type token)
{
	vars->command = NONE;
	vars->pipe = NONE;
	vars->redirection = NONE;
	if (token == e_simple_word)
		vars->command = EXIST;
	else if (token == e_pipe)
		vars->pipe = EXIST;
	else if (token == less || token == great || token == double_great
		|| token == double_less)
		vars->redirection = EXIST;
}

void	initialize_tokens_vars(t_vars *vars)
{
	vars->command = NONE;
	vars->redirection = NONE;
	vars->pipe = NONE;
	vars->error = NONE;
}

int	check_tokens_syntax(t_tokens *tokens_list)
{
	t_tokens	*curr_token_node;
	t_vars		vars;
	int			type;

	curr_token_node = tokens_list;
	initialize_tokens_vars(&vars);
	while (curr_token_node && vars.error == NONE)
	{
		type = curr_token_node->type;
		if (type == e_simple_word)
			check_word_token_order(&vars, curr_token_node->data);
		else if (type == e_pipe)
			check_pipe_token_order(&vars);
		else if (type == e_semicolon)
			check_semicolon_token_order(&vars);
		else if (type == less || type == great || type == double_great
			|| type == double_less)
			check_redirection_token_order(&vars, type);
		else if (type == newline)
			check_newline_token_order(&vars);
		curr_token_node = curr_token_node->next;
		if (vars.error == EXIST)
			return (ERROR);
	}
	return (VALID);
}
