/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <iariss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 10:57:19 by iariss            #+#    #+#             */
/*   Updated: 2021/07/17 13:46:35 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"
#include "file_bonus.h"

void	exv(t_ast *scn, t_varso *vars)
{
	t_exv_vars	exv;

	getcwd(exv.cwd, sizeof(exv.cwd));
	exv.path = find_env("PATH");
	if (exv.path && scn->node.data.args_vec.elements[0][0])
	{
		with_path(exv.path, vars, scn);
	}
	else if (!exv.path && (scn->node.data.args_vec.elements[0][0] == '/'
		|| !ft_strncmp(scn->node.data.args_vec.elements[0], "./", 2)))
		without_path_slash(vars, scn);
	else
	{
		print_error("minishell: ");
		print_error(scn->node.data.args_vec.elements[0]);
		print_error(": command not found\n");
		g_vars.last_err_num = 127;
	}
	return ;
}
