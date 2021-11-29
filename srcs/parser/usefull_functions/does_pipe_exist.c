/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   does_pipe_exist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:05:22 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/15 20:06:11 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./usefull_functions.h"

int	does_pipe_exist(char c, t_quotes *quotes)
{
	if (c == ' ')
		return (quotes->pipe);
	if (c == PIPE && quotes->backslash == NONE && quotes->curr_state == CLOSED)
	{
		quotes->pipe = EXIST;
		return (EXIST);
	}
	else
		quotes->pipe = NONE;
	return (NONE);
}
