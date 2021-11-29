/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_w_path_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <iariss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:10:18 by iariss            #+#    #+#             */
/*   Updated: 2021/07/17 13:45:53 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_bonus.h"

void	free_vars(t_rand num, t_varso *vars)
{
	num.i = 0;
	while (num.tab[num.i])
		free(num.tab[num.i++]);
	free(num.tab);
	num.i = 0;
	while (vars->export.env[num.i])
		free(vars->export.env[num.i++]);
	free(vars->export.env);
}

void	execv_errors(t_rand *num, t_ast *scn, struct stat buff)
{
	if (stat(num->tab[num->i], &buff) && scn->node.data.args_vec.elements[0][0]
	!= '/' && ft_strncmp(scn->node.data.args_vec.elements[0], "./", 2) &&
	(!ft_strchr(scn->node.data.args_vec.elements[0], '/')))
	{
		print_three("minishell: ", scn->node.data.args_vec.elements[0],
			(": command not found\n"));
		g_vars.last_err_num = 127;
	}
	else if ((scn->node.data.args_vec.elements[0][0] == '/'
		|| (!ft_strncmp(scn->node.data.args_vec.elements[0], "./", 2)
			|| (ft_strchr(scn->node.data.args_vec.elements[0], '/'))))
			&& (num->y || !num->command_exists))
	{
		status_check_w_err(num, scn, buff);
	}
}

void	ex(t_rand *num, t_varso *vars, t_ast *scn)
{
	num->pid = fork();
	if (num->pid == 0)
	{
		if (execve(num->tab[num->i], scn->node.data.args_vec.elements,
				vars->export.env) == -1)
			exit(1);
	}
	waitpid(num->pid, &num->status, 0);
	if (WIFEXITED(num->status))
		g_vars.last_err_num = WEXITSTATUS(num->status);
	if (WEXITSTATUS(num->status)
		&& ft_strcmp(scn->node.data.args_vec.elements[0], "./minishell"))
		num->y = 1;
}

void	execv_main_loop(t_rand *num, t_ast *scn, t_varso *vars)
{
	while (num->tab[num->i])
	{
		num->y = 0;
		num->x = 0;
		if (!check_command(scn, num->sticker, vars, num))
			return ;
		if (!stat(num->tab[num->i], &num->buff))
		{
			ex(num, vars, scn);
			break ;
		}
		num->i++;
	}
}

void	with_path(char *path, t_varso *vars, t_ast *scn)
{
	char	cwd[PATH_MAX];
	t_rand	num;
	int		k;

	k = 0;
	num.tab = ft_split(path, ':');
	getcwd(cwd, sizeof(cwd));
	num.command_exists = 1;
	num.sticker = scn->node.data.args_vec.elements[0];
	if (scn->node.data.args_vec.elements[0][0] != '/')
	{
		num.sticker = ft_strjoin("/", scn->node.data.args_vec.elements[0]);
		k = 1;
	}
	merge_env(vars);
	num.i = 0;
	execv_main_loop(&num, scn, vars);
	if (stat(num.tab[num.i], &num.buff))
		num.command_exists = 0;
	execv_errors(&num, scn, num.buff);
	if (k)
		free(num.sticker);
	free_vars(num, vars);
}
