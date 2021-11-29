/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_right_arrow_action.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:50:58 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/02 11:45:09 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline.h"

void	start_right_arrow_action(t_rdline *rdl_vars)
{
	if (rdl_vars->tab_mode == on)
		return ;
	quit_highlighting_mode(rdl_vars, right_arrow);
	move_right(rdl_vars);
	rdl_vars->previous_key = right_arrow;
}
