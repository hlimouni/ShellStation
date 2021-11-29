/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:14:04 by iariss            #+#    #+#             */
/*   Updated: 2021/07/17 12:08:45 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file_bonus.h"
#include "../minishell_bonus.h"

char	*find_env(char *targ)
{
	int	i;

	i = 0;
	while (i < g_vars.env_table.name.used_size)
	{
		if (!(ft_strncmp(g_vars.env_table.name.elements[i],
					targ, ft_strlen(targ))))
		{
			return (g_vars.env_table.value.elements[i]);
		}
		i++;
	}
	return (NULL);
}

void	handle_quit(int sig_num)
{
	if (sig_num == SIGQUIT)
	{
		g_vars.last_err_num = 131;
		write(2, "Quit: 3\n", 8);
	}
}

void	handle_c(int sig_num)
{
	if (sig_num == SIGINT)
	{
		g_vars.last_err_num = 130;
		write(2, "\n", 1);
	}
}

void	pwd(void)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)))
		printf("%s\n", cwd);
	else if (find_env("PWD"))
		printf("%s\n", find_env("PWD"));
	else
	{
		g_vars.last_err_num = 1;
		print_error("error retrieving current directory: getcwd: cannot ");
		print_error("access parent directories: No such file or directory\n");
		return ;
	}
	g_vars.last_err_num = 0;
}
