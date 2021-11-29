/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_width_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:47:48 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:11:48 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline_bonus.h"

int	get_screen_width(void)
{
	struct winsize	window;

	ioctl(g_vars.rdl_vars.tty_fd, TIOCGWINSZ, &window);
	return (window.ws_col);
}
