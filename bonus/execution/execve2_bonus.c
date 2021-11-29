/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/03 16:47:17 by iariss            #+#    #+#             */
/*   Updated: 2021/07/17 12:08:22 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_bonus.h"
#include "../minishell_bonus.h"

void	normal_commands(t_rand *num, t_ast *scn)
{
	free(num->tab[num->i]);
	num->tab[num->i] = ft_strdup(scn->node.data.args_vec.elements[0]);
}

void	check_command2(char *sticker, t_varso *vars, t_rand *num, t_ast *scn)
{
	char	*tmp;
	char	cwd[PATH_MAX];

	getcwd(cwd, sizeof(cwd));
	if (scn->node.data.args_vec.elements[0][0] != '/'
		&& ft_strncmp(scn->node.data.args_vec.elements[0], "./", 2))
	{
		tmp = num->tab[num->i];
		num->tab[num->i] = ft_strjoin(num->tab[num->i], sticker);
		free(tmp);
	}
	else if (!ft_strncmp(scn->node.data.args_vec.elements[0], "./", 2))
	{
		free(num->tab[num->i]);
		num->tab[num->i] = ft_strjoin(cwd, sticker + 2);
		if (!ft_strcmp(scn->node.data.args_vec.elements[0], "./minishell")
			|| !ft_strcmp(scn->node.data.args_vec.elements[0], "./MINISHELL"))
		{	
			signal(SIGQUIT, SIG_IGN);
			signal(SIGINT, SIG_IGN);
			add_one(vars);
		}
	}
	else
		normal_commands(num, scn);
}

int	check_command(t_ast *scn, char *sticker, t_varso *vars, t_rand *num)
{
	if (!ft_strcmp(scn->node.data.args_vec.elements[0], "./"))
	{
		print_error("minishell: ./: is a directory\n");
		g_vars.last_err_num = 126;
		return (0);
	}
	else if (!ft_strcmp(scn->node.data.args_vec.elements[0], "."))
	{
		g_vars.last_err_num = 2;
		print_error("minishell: .: filename argument required\n");
		print_error(".: usage: . filename [arguments]\n");
		return (0);
	}
	else
		check_command2(sticker, vars, num, scn);
	return (1);
}
