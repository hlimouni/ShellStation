/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_quotes_special_meaning_bonus.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:39:12 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:10:32 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./expanding_bonus.h"

void	replace_double_quotes(char *c, t_quotes quotes)
{
	if (quotes.double_quotes == OPEND
		|| quotes.double_quotes == CLOSED)
		*c = SP_DOUBLE_QUOTES;
}

void	replace_single_quotes(char *c, t_quotes quotes)
{
	if (quotes.single_quotes == OPEND || quotes.single_quotes == CLOSED)
		*c = SP_SINGLE_QUOTES;
}

void	replace_backslash(char *c, t_quotes quotes)
{
	if (quotes.backslash == EXIST)
	{
		if (quotes.double_quotes == OPEND)
		{
			if (ft_strchr("$`\"\\", *(c + 1)))
				*c = SP_BACKSLASH;
		}
		else if (quotes.single_quotes == CLOSED)
			*c = SP_BACKSLASH;
	}
}

void	give_quotes_special_meaning(char *str)
{
	int			i;
	t_quotes	quotes;

	i = 0;
	initialize_quotes_vars(&quotes);
	while (str[i] != '\0')
	{
		open_and_close_quotes(str[i], &quotes);
		change_quotes_state(&quotes);
		if (quotes.curr_state != quotes.old_state)
		{
			if (str[i] == SINGLE_QUOTES)
				replace_single_quotes(&str[i], quotes);
			else if (str[i] == DOUBLE_QUOTES)
				replace_double_quotes(&str[i], quotes);
		}
		does_backslash_exist(str[i], &quotes);
		if (quotes.backslash == EXIST)
			replace_backslash(&str[i], quotes);
		i++;
	}
}
