/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_up_arrow_action_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:50:45 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:13:57 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline_bonus.h"

void	start_up_arrow_action(t_rdline *rdl_vars)
{
	if (rdl_vars->tab_mode == on)
		return ;
	quit_highlighting_mode(rdl_vars, up_arrow);
	show_old_history(rdl_vars);
	rdl_vars->previous_key = up_arrow;
}
