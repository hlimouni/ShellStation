/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_status_check_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <iariss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:04:06 by iariss            #+#    #+#             */
/*   Updated: 2021/07/17 13:50:38 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_bonus.h"
#include "../minishell_bonus.h"

void	status_check(t_redirection_vars *red)
{
	struct stat	buff;

	if (!stat(red->head.redirections->file, &buff))
	{
		if (buff.st_mode & S_IFDIR)
			print_three("minishell:",
				red->head.redirections->file, ": Is a directory\n");
		else
			print_three("minishell:",
				red->head.redirections->file, ": Permission denied\n");
	}
	else
		print_three("minishell: ", red->head.redirections->file,
			": No such file or directory\n");
}

void	status_check_w_err(t_rand *num, t_ast *scn, struct stat buff)
{
	if (!stat(num->tab[num->i], &buff))
	{
		if (buff.st_mode & S_IFDIR)
		{
			print_three("minishell: ", scn->node.data.args_vec.elements[0],
				(": is a directory\n"));
			g_vars.last_err_num = 126;
		}
		else if (open(scn->node.data.args_vec.elements[0], O_RDONLY) != -1
			&& !(buff.st_mode & S_IXUSR))
		{
			print_three("minishell: ", scn->node.data.args_vec.elements[0],
				(": Permission denied\n"));
			g_vars.last_err_num = 126;
		}
	}
	else
	{
		g_vars.last_err_num = 127;
		print_three("minishell: ", scn->node.data.args_vec.elements[0],
			": No such file or directory\n");
	}
}
