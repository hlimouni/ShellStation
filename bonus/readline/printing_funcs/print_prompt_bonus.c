/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prompt_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:49:18 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:13:04 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../readline_bonus.h"

void	print_prompt(t_rdline *rdl_vars)
{
	int		i;
	char	*prompt;

	i = 0;
	prompt = rdl_vars->prompt;
	if (prompt != NULL)
	{
		ft_putstr_fd(GRN, rdl_vars->tty_fd);
		while (prompt[i] != ' ')
			put_char(prompt[i++]);
		ft_putstr_fd(CYN, rdl_vars->tty_fd);
		while (prompt[i] != '\0')
			put_char(prompt[i++]);
		ft_putstr_fd(WHT, rdl_vars->tty_fd);
	}
	else
	{
		ft_putstr_fd(GRN, rdl_vars->tty_fd);
		ft_putstr_fd("➜ ", rdl_vars->tty_fd);
		ft_putstr_fd(WHT, rdl_vars->tty_fd);
		rdl_vars->prompt_len = ft_strlen_utf8("➜ ");
	}
}
