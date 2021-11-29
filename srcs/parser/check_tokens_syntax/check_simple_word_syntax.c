/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_simple_word_syntax.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:33:09 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/11 15:50:48 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_tokens_syntax.h"
#include "../usefull_functions/usefull_functions.h"

void	check_simple_word_syntax(char *token, t_vars *vars)
{
	int			i;
	t_quotes	quotes;

	i = 0;
	initialize_quotes_vars(&quotes);
	while (token[i] != '\0')
	{
		open_and_close_quotes(token[i], &quotes);
		does_backslash_exist(token[i], &quotes);
		i++;
	}
	if (quotes.double_quotes == OPEND || quotes.single_quotes == OPEND
		|| quotes.backslash == EXIST)
	{
		vars->error = EXIST;
		g_vars.last_err_num = 258;
		ft_putstr_fd("> Error: multiline commands not allowed\n",
			STDERR_FILENO);
	}
}
