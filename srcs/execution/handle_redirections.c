/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_redirections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 12:44:38 by hlimouni          #+#    #+#             */
/*   Updated: 2021/12/24 12:51:32 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	ft_heredoc(t_ast *data, t_redirection *redirs)
{
	int	fd[2];

	pipe(fd);
	write(fd[1], redirs->file, ft_strlen(redirs->file));
	close(fd[1]);
	data->node.data.in_fd = fd[0];
}

static int	ft_redir_file(t_ast *data, t_redirection *redirs, int open_flag)
{
	int		fd;
	char	dir;

	dir = *(redirs->type);
	if (dir == '>' && data->node.data.out_fd != 1)
		close(data->node.data.out_fd);
	if (dir == '<' && data->node.data.in_fd != 0)
		close(data->node.data.in_fd);
	fd = open(redirs->file, open_flag, 0644);
	if (fd == -1)
	{
		printf("minishell: %s: %s\n", redirs->file, strerror(errno));
		g_vars.last_err_num = 1;
		return (1);
	}
	if (dir == '>')
		data->node.data.out_fd = fd;
	if (dir == '<')
		data->node.data.in_fd = fd;
	return (0);
}

static int	file_redirs(t_redirection *redirs, t_ast *curr_data)
{
	if (!(ft_strcmp(redirs->type, ">")))
	{
		if (ft_redir_file(curr_data, redirs, O_TRUNC | O_WRONLY
				| O_CREAT))
			return (1);
	}
	else if (!(ft_strcmp(redirs->type, "<")))
	{
		if (ft_redir_file(curr_data, redirs, O_RDONLY))
			return (1);
	}
	else if (!(ft_strcmp(redirs->type, ">>")))
	{
		if (ft_redir_file(curr_data, redirs, O_APPEND | O_WRONLY
				| O_CREAT))
			return (1);
	}
	return (0);
}

int	handle_redirections(t_ast *curr_data)
{
	t_redirection	*redirs;

	redirs = curr_data->node.data.redirections;
	while (redirs)
	{
		if (!(ft_strcmp(redirs->type, "<<")))
			ft_heredoc(curr_data, redirs);
		else
		{
			if (file_redirs(redirs, curr_data))
				return (1);
		}
		redirs = redirs->next;
	}
	return (0);
}
