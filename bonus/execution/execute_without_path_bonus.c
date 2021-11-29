/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_without_path_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:18:30 by iariss            #+#    #+#             */
/*   Updated: 2021/07/17 12:08:13 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_bonus.h"

void	execute_path(int *y, t_ast *scn, t_varso *vars)
{
	pid_t	pid;
	int		status;

	if (!ft_strcmp(scn->node.data.args_vec.elements[0], "./minishell")
		|| !ft_strcmp(scn->node.data.args_vec.elements[0], "./MINISHELL"))
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, SIG_IGN);
		add_one(vars);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(scn->node.data.args_vec.elements[0],
				scn->node.data.args_vec.elements, vars->export.env) == -1)
			exit(1);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_vars.last_err_num = WEXITSTATUS(status);
	if (WEXITSTATUS(status))
		*y = 1;
}

void	error_handling(t_ast *scn, int y)
{
	struct stat	buff;

	if (!stat(scn->node.data.args_vec.elements[0], &buff) && y)
	{
		if (buff.st_mode & S_IFDIR)
		{
			print_three("minishell: ", scn->node.data.args_vec.elements[0],
				": is a directory\n");
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
	else if (stat(scn->node.data.args_vec.elements[0], &buff))
	{
		g_vars.last_err_num = 127;
		print_three("minishell: ", scn->node.data.args_vec.elements[0],
			(": No such file or directory\n"));
	}
}

void	without_path_slash(t_varso *vars, t_ast *scn)
{
	int			y;
	struct stat	buff;
	int			i;

	y = 0;
	i = 0;
	merge_env(vars);
	if (!stat(scn->node.data.args_vec.elements[0], &buff))
		execute_path(&y, scn, vars);
	error_handling(scn, y);
	while (vars->export.env[i])
		free(vars->export.env[i++]);
	free(vars->export.env);
}
