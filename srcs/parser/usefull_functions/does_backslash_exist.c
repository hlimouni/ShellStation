/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   does_backslash_exist.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:05:35 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/15 20:05:53 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./usefull_functions.h"

int	does_backslash_exist(char c, t_quotes *quotes)
{
	if ((c == BACKSLASH || c == SP_BACKSLASH) && quotes->backslash == NONE)
	{
		quotes->backslash = EXIST;
		return (EXIST);
	}
	else
		quotes->backslash = NONE;
	return (NONE);
}
