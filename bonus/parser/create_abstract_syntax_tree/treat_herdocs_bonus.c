/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_herdocs_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 17:55:27 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:10:04 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./create_abstract_syntax_tree_bonus.h"

static void	set_and_restore_signals(int option)
{
	if (option == set_sig)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (option == restore_sig)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
}

static int	is_delimiter_quoted(char *delimiter, char **unquoted_delimiter)
{
	int			i;
	int			is_quoted;
	t_quotes	quotes;
	t_char_vec	vec;

	i = -1;
	is_quoted = false;
	initialize_vec_of_char(&vec);
	initialize_quotes_vars(&quotes);
	while (delimiter[++i] != '\0')
	{
		open_and_close_quotes(delimiter[i], &quotes);
		change_quotes_state(&quotes);
		if (quotes.curr_state != quotes.old_state)
		{
			is_quoted = true;
			continue ;
		}
		vec.add_new_element(&vec, delimiter[i]);
		does_backslash_exist(delimiter[i], &quotes);
	}
	*unquoted_delimiter = vec.elements;
	return (is_quoted);
}

static void	store_expanded_heredocs(char *buffer_to_expand, t_char_vec *vec)
{
	int			i;
	int			is_expanded;
	t_quotes	quotes;

	i = 0;
	is_expanded = 0;
	initialize_quotes_vars(&quotes);
	while (buffer_to_expand[i])
	{
		if (buffer_to_expand[i] == DOLLAR && quotes.backslash == NONE)
		{
			is_expanded = expand_quoted_var(buffer_to_expand, &i, vec);
			if (is_expanded == true)
				continue ;
		}
		does_backslash_exist(buffer_to_expand[i], &quotes);
		if (quotes.backslash == EXIST && buffer_to_expand[i + 1] == DOLLAR)
		{
			i++;
			continue ;
		}
		vec->add_new_element(vec, buffer_to_expand[i++]);
	}
}

static char	*expand_heredocs_lines(char *buffer_to_expand, int is_quoted)
{
	t_char_vec	expanded_buffer_vec;

	if (is_quoted == false)
	{
		initialize_vec_of_char(&expanded_buffer_vec);
		store_expanded_heredocs(buffer_to_expand, &expanded_buffer_vec);
	}
	else
		return (ft_strdup(buffer_to_expand));
	return (expanded_buffer_vec.elements);
}

char	*treat_heredocs(char *delimiter)
{
	int			is_quoted;
	char		*herdoc_line;
	char		*expanded_heredoc;
	char		*unqtd_delimiter;
	t_char_vec	buffer_vec;

	set_and_restore_signals(set_sig);
	is_quoted = is_delimiter_quoted(delimiter, &unqtd_delimiter);
	initialize_vec_of_char(&buffer_vec);
	while (true)
	{
		herdoc_line = readline(">> ");
		if (herdoc_line == NULL || ft_strcmp(herdoc_line, unqtd_delimiter) == 0)
			break ;
		buffer_vec.add_set_of_elements(&buffer_vec, herdoc_line);
		buffer_vec.add_new_element(&buffer_vec, '\n');
		free(herdoc_line);
	}
	free(herdoc_line);
	expanded_heredoc = expand_heredocs_lines(buffer_vec.elements, is_quoted);
	buffer_vec.free(&buffer_vec);
	free(unqtd_delimiter);
	set_and_restore_signals(restore_sig);
	return (expanded_heredoc);
}
