/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <iariss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 10:55:47 by iariss            #+#    #+#             */
/*   Updated: 2021/07/17 13:54:07 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell_bonus.h"
#include "file_bonus.h"

int	check_exit_num(char *num, int j)
{
	char	*max_long;
	int		len;

	max_long = "9223372036854775807";
	len = ft_strlen(num);
	if (num[0] != '-' && (len != j || (len > 19 && num[0] != '0')
			|| (len == 19 && ft_strncmp(max_long, num, len) < 0)))
	{
		print_three("exit\nminishell: exit: ", num,
			": numeric argument required\n");
		exit(255);
	}
	else if (num[0] == '-' && (len != j || (len > 20 && num[0] != '0')
			|| (len == 20 && ft_strncmp(max_long, num, len) < 0)))
	{
		print_three("exit\nminishell: exit: ", num,
			 ": numeric argument required\n");
		exit(255);
	}
	else
	{
		printf("exit\n");
		exit(ft_atoi(num));
	}
}

void	one_exit_arg(t_ast *scn, int i)
{
	int	j;

	j = 0;
	while (scn->node.data.args_vec.elements[i][j])
	{
		if (!ft_isdigit(scn->node.data.args_vec.elements[i][j])
			&& scn->node.data.args_vec.elements[i][0] != '-')
			break ;
		j++;
	}
	check_exit_num(scn->node.data.args_vec.elements[i], j);
}

void	multi_exit_arg(t_ast *scn, int i)
{
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(scn->node.data.args_vec.elements[i]);
	while (scn->node.data.args_vec.elements[i][j])
	{
		if (!ft_isdigit(scn->node.data.args_vec.elements[i][j]))
			break ;
		j++;
	}
	if (len != j)
	{
		print_error("exit\nminishell: exit: ");
		print_error(scn->node.data.args_vec.elements[i]);
		print_error(": numeric argument required\n");
		exit(255);
	}
	print_error("exit\nminishell: exit: too many arguments\n");
	g_vars.last_err_num = 1;
}

void	check_exit(t_ast *scn, int x)
{
	int		i;
	int		j;

	j = 0;
	i = 1;
	while (i <= scn->node.data.args_vec.last_index)
	{
		if (scn->node.data.args_vec.last_index == 1)
			one_exit_arg(scn, i);
		else if (scn->node.data.args_vec.last_index > 1)
		{
			multi_exit_arg(scn, i);
			break ;
		}
		i++;
	}
	if (scn->node.data.args_vec.last_index == 0)
	{
		overwrite_history_file(&g_vars.rdl_vars);
		exit(x);
	}
}
