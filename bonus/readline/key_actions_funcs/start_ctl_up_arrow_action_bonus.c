/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_ctl_up_arrow_action_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:51:31 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:14:27 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline_bonus.h"

void	start_ctl_up_arrow_action(t_rdline *rdl_vars)
{
	if (rdl_vars->tab_mode == on)
		return ;
	quit_highlighting_mode(rdl_vars, ctl_up_arrow);
	move_up_vertically(rdl_vars);
	rdl_vars->previous_key = ctl_up_arrow;
}
