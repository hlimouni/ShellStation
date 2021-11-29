/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_treating_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:39:30 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:10:40 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenization_bonus.h"

int	treat_quotes(char *line, char sd_quote)
{
	int		i;
	int		backslash;

	i = 1;
	backslash = 0;
	while (line[i] != '\0' && (backslash == EXIST || line[i] != sd_quote))
	{
		if ((line)[i] == BACKSLASH && backslash == NONE
			&& sd_quote == DOUBLE_QUOTES)
			backslash = EXIST;
		else
			backslash = NONE;
		i++;
	}
	return (i);
}

char	*get_redirection(char **line, t_type *type)
{
	int		count;
	int		max;
	char	redir;
	char	*token;

	count = 0;
	redir = **line;
	max = 2;
	while ((*line)[count] == redir && (*line)[count] != '\0' && count < max)
		count++;
	token = ft_substr(*line, 0, count);
	*line = *line + count;
	if (redir == '<' && count == 1)
		*type = less;
	else if (redir == '<' && count == 2)
		*type = double_less;
	else if (redir == '>' && count == 1)
		*type = great;
	else if (redir == '>' && count == 2)
		*type = double_great;
	return (token);
}

char	*get_pipe(char **line, t_type *type)
{
	char	*token;

	token = ft_substr(*line, 0, 1);
	*line = *line + 1;
	*type = e_pipe;
	return (token);
}

char	*get_semicolon(char **line, t_type *type)
{
	char	*token;

	token = ft_substr(*line, 0, 1);
	*line = *line + 1;
	*type = e_semicolon;
	return (token);
}

char	*get_simple_word(char **line, t_type *type)
{
	int		i;
	char	*token;
	int		backslash;

	i = 0;
	backslash = 0;
	while ((!ft_strchr(" |;<>", (*line)[i]) || backslash == EXIST)
		&& (*line)[i] != '\0')
	{
		if ((*line)[i] == DOUBLE_QUOTES && backslash == NONE)
			i += treat_quotes(*line + i, DOUBLE_QUOTES);
		else if ((*line)[i] == SINGLE_QUOTES && backslash == NONE)
			i += treat_quotes(*line + i, SINGLE_QUOTES);
		if ((*line)[i] == BACKSLASH && backslash == NONE)
			backslash = EXIST;
		else
			backslash = NONE;
		if ((*line)[i] != '\0')
			i++;
	}
	token = ft_substr(*line, 0, i);
	*line = *line + i;
	*type = e_simple_word;
	return (token);
}
