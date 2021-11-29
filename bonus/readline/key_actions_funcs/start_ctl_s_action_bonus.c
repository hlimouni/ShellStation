/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_ctl_s_action_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:51:36 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:14:29 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline_bonus.h"

void	start_ctl_s_action(t_rdline *rdl_vars)
{
	if (rdl_vars->tab_mode == on)
		return ;
	copy_highlighted_text(rdl_vars);
	rdl_vars->previous_key = ctl_s;
}
