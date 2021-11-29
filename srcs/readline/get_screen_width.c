/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_screen_width.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:47:48 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/13 19:47:49 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "readline.h"

int	get_screen_width(void)
{
	struct winsize	window;

	ioctl(g_vars.rdl_vars.tty_fd, TIOCGWINSZ, &window);
	return (window.ws_col);
}
