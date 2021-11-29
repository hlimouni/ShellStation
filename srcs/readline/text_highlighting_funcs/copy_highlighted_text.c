/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_highlighted_text.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:48:44 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/13 19:48:45 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline.h"

void	copy_highlighted_text(t_rdline *rdl_vars)
{
	int				beg;
	int				last;
	int				hilitd_txt_len;
	char			*hstry_str;
	t_vchar_vec		*history_vec;

	if (rdl_vars->reverse_video_mode == 1)
	{
		determine_beg_last_highlighted_txt_indx(rdl_vars);
		beg = rdl_vars->beg_hilitd_index;
		last = rdl_vars->last_hilitd_index;
		hilitd_txt_len = last - beg;
		history_vec = &rdl_vars->history_vec;
		hstry_str = history_vec->elements[rdl_vars->l_i].elements;
		if (rdl_vars->hilitd_txt != NULL)
			free(rdl_vars->hilitd_txt);
		rdl_vars->hilitd_txt = malloc(sizeof(char) * (hilitd_txt_len + 1));
		ft_strlcpy(rdl_vars->hilitd_txt, hstry_str + beg, hilitd_txt_len + 1);
	}
}
