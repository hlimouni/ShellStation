/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:35:38 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:31:34 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./expanding_bonus.h"

void	expand_args_vec(t_str_vec *args_vec)
{
	int			i;

	i = 0;
	while (args_vec->elements[i])
	{
		give_quotes_special_meaning(args_vec->elements[i]);
		expand_dollar_vars(&args_vec->elements[i]);
		split_element_to_args(args_vec, &i);
	}
}

int	check_ambiguous_redirect(char *file)
{
	int		i;
	char	*name;
	char	*value;

	i = 0;
	while (file[i])
	{
		if (file[i] == '$')
		{
			name = get_dollar_name(file, &i);
			if (name != NULL)
			{
				value = get_dollar_value(name);
				free(name);
				if (value != NULL)
					return (NONE);
			}
			else
				return (NONE);
		}
		else
			return (NONE);
	}
	return (EXIST);
}

int	expand_redirection_list(t_redirection *rdir_list)
{
	t_redirection	*curr_redir_node;

	curr_redir_node = rdir_list;
	while (curr_redir_node != NULL)
	{
		if (ft_strcmp(curr_redir_node->type, "<<") != 0)
		{
			if (check_ambiguous_redirect(curr_redir_node->file) == EXIST)
			{
				printf("bash: %s: ambiguous redirect\n", curr_redir_node->file);
				g_vars.last_err_num = 1;
				return (ERROR);
			}
			give_quotes_special_meaning(curr_redir_node->file);
			expand_dollar_vars(&curr_redir_node->file);
			remove_special_quotes(&curr_redir_node->file);
		}
		curr_redir_node = curr_redir_node->next;
	}
	return (NONE);
}

int	expand_curr_cmd(t_ast *curr_simple_cmd)
{
	int		error;
	t_ast	*data;

	error = NONE;
	data = curr_simple_cmd->node.dir.bottom;
	expand_args_vec(&data->node.data.args_vec);
	error = expand_redirection_list(data->node.data.redirections);
	if (error == NONE)
		g_vars.last_err_num = 0;
	return (error);
}
