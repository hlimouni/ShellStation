/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:07:31 by hlimouni          #+#    #+#             */
/*   Updated: 2021/12/24 12:12:42 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

void	ft_pwd(void)
{
	char	cwd[PATH_MAX];
	char	*working_dir;

	working_dir = get_value_of_env_name(g_vars.env_table, "PWD");
	if (working_dir)
		printf("%s\n", working_dir);
	else if (getcwd(cwd, sizeof(cwd)))
		printf("%s\n", cwd);
	else
	{
		perror("minishell");
		g_vars.last_err_num = 1;
		return ;
	}
}
