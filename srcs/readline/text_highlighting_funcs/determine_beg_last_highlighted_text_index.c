/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   determine_beg_last_highlighted_text_index.c        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:48:35 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/13 19:48:36 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline.h"

void	determine_beg_last_highlighted_txt_indx(t_rdline *rdl_v)
{
	if (rdl_v->starting_hilitd_index < rdl_v->curr_hilitd_char_index)
	{
		rdl_v->beg_hilitd_index = rdl_v->starting_hilitd_index;
		rdl_v->last_hilitd_index = rdl_v->curr_hilitd_char_index;
	}
	else
	{
		rdl_v->beg_hilitd_index = rdl_v->curr_hilitd_char_index;
		rdl_v->last_hilitd_index = rdl_v->starting_hilitd_index;
	}
}
