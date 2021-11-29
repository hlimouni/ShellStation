/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   does_pipe_exist_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:05:22 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:10:47 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./usefull_functions_bonus.h"

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
