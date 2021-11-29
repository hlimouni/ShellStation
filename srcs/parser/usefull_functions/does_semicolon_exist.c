/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   does_semicolon_exist.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:04:24 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/15 20:06:28 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./usefull_functions.h"

int	does_semicolon_exist(char c, t_quotes *quotes)
{
	if (c == ' ')
		return (quotes->semicolon);
	if (c == SEMICOLON && quotes->backslash == NONE
		&& quotes->curr_state == CLOSED)
	{
		quotes->semicolon = EXIST;
		return (EXIST);
	}
	else
		quotes->semicolon = NONE;
	return (NONE);
}
