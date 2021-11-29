/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   does_semicolon_exist_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:04:24 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:10:49 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./usefull_functions_bonus.h"

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
