/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_ctl_left_arrow_action.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:51:44 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/02 11:43:18 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline.h"

void	start_ctl_left_arrow_action(t_rdline *rdl_vars)
{
	if (rdl_vars->tab_mode == on)
		return ;
	quit_highlighting_mode(rdl_vars, ctl_left_arrow);
	move_to_prec_word(rdl_vars);
	rdl_vars->previous_key = ctl_left_arrow;
}
