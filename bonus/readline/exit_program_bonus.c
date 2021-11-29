/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 20:13:48 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:11:51 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./readline_bonus.h"

void	exit_program(t_rdline *rdl_vars)
{
	t_vchar_vec		*history_vec;
	t_char_vec		*history_line;

	history_vec = &rdl_vars->history_vec;
	history_line = history_vec->elements;
	if (history_line[rdl_vars->l_i].used_size == 0)
	{
		g_vars.rdl_vars.history_vec.delete_last_element(history_vec);
		overwrite_history_file(rdl_vars);
		ft_putstr_fd("exit\n", rdl_vars->tty_fd);
		exit(0);
	}
}
