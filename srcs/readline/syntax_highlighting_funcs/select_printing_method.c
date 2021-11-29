/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_printing_method.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 21:48:57 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/16 11:12:45 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline.h"

void	select_printing_method(t_rdline *rdl_vars)
{
	char	*value;

	value = getenv("SYNTAX_HIGHLIGHTING");
	if (value == NULL)
		rdl_vars->syntax_highlighting = off;
	else
	{
		if (ft_strcmp(value, "ON") == 0)
			rdl_vars->syntax_highlighting = on;
		else
			rdl_vars->syntax_highlighting = off;
	}
	value = getenv("AUTO_SUGGESTIONS");
	if (value == NULL)
		rdl_vars->auto_suggestions = off;
	else
	{
		if (ft_strcmp(value, "ON") == 0)
			rdl_vars->auto_suggestions = on;
		else
			rdl_vars->auto_suggestions = off;
	}
}
