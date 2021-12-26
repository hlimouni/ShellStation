/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_level_signals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:16:35 by hlimouni          #+#    #+#             */
/*   Updated: 2021/12/26 11:35:00 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

/*
** static void	sig_handler_child(int sig_num)
** {
** 	if (sig_num == SIGINT)
** 		g_vars.last_err_num = 130;
** 	if (sig_num == SIGQUIT)
** 		g_vars.last_err_num = 131;
** }
*/

static void	sig_handler_main(int sig_num)
{
	if (sig_num == SIGINT)
	{
		write(2, "\n", 1);
	}
	if (sig_num == SIGQUIT)
	{
		write(2, "Quit: 3\n", 8);
	}
}

void	main_signals(void)
{
	signal(SIGINT, sig_handler_main);
	signal(SIGQUIT, sig_handler_main);
}

/*
** void	child_signals(void)
** {
** 	signal(SIGINT, sig_handler_child);
** 	signal(SIGQUIT, sig_handler_child);
** }
*/
