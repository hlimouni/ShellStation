/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:34:20 by hlimouni          #+#    #+#             */
/*   Updated: 2021/12/23 19:39:25 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

t_ast	*ft_find_command(int pid, t_ast *pipeline_seq)
{
	int		i;
	t_ast	*curr_smpl_cmd;

	curr_smpl_cmd = pipeline_seq->node.pipe.dir.bottom;
	i = 0;
	while (curr_smpl_cmd)
	{
		if (pipeline_seq->node.pipe.pids[i] == pid)
			return (curr_smpl_cmd->node.dir.bottom);
		i++;
		curr_smpl_cmd = curr_smpl_cmd->node.dir.next;
	}
	return (NULL);
}

void	sig_handler_child(int sig_num)
{
	if (sig_num == SIGINT)
		g_vars.last_err_num = 130;
	if (sig_num == SIGQUIT)
		g_vars.last_err_num = 131;
}

void	sig_handler_main(int sig_num)
{
	if (sig_num == SIGINT)
	{
		g_vars.last_err_num = 130;
		write(2, "\n", 1);
	}
	if (sig_num == SIGQUIT)
	{
		g_vars.last_err_num = 131;
		write(2, "Quit: 3\n", 8);
	}
}

void	main_signals(void)
{
	signal(SIGINT, sig_handler_main);
	signal(SIGQUIT, sig_handler_main);
}

void	child_signals(void)
{
	signal(SIGINT, sig_handler_child);
	signal(SIGQUIT, sig_handler_child);
}

static void	ft_update_status(int terminated_pid, int status,
				t_ast	*pipeline_seq)
{
	t_ast	*curr_data;

	if (terminated_pid == pipeline_seq
		->node.pipe.pids[pipeline_seq->node.pipe.pipes_count])
	{
		if (!WTERMSIG(status))
			g_vars.last_err_num = WEXITSTATUS(status);
		else
			g_vars.last_err_num = WTERMSIG(status) + 128;
	}
	curr_data = ft_find_command(terminated_pid, pipeline_seq);
	if (curr_data)
	{
		if (curr_data->node.data.out_fd != 1)
			close(curr_data->node.data.out_fd);
		if (curr_data->node.data.in_fd != 0)
			close(curr_data->node.data.in_fd);
	}
}

static void	wait_for_children(t_ast *pipeline_seq)
{
	int		i;
	int		status;

	i = 0;
	while (i <= pipeline_seq->node.pipe.pipes_count)
	{
		ft_update_status(wait(&status), status, pipeline_seq);
		i++;
	}
}

void	ft_init_pipe(t_ast *curr_data, t_ast *prev_data)
{
	int	fd[2];

	pipe(fd);
	if (prev_data->node.data.out_fd != 1)
		close(fd[1]);
	else
		prev_data->node.data.out_fd = fd[1];
	if (curr_data->node.data.in_fd != 0)
		close(fd[0]);
	else
		curr_data->node.data.in_fd = fd[0];
}

void	ft_heredoc(t_ast *data, t_redirection *redirs)
{
	int	fd[2];

	pipe(fd);
	write(fd[1], redirs->file, ft_strlen(redirs->file));
	close(fd[1]);
	data->node.data.in_fd = fd[0];
}

int	ft_redir_file(t_ast *data, t_redirection *redirs, int open_flag)
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

int	file_redirs(t_redirection *redirs, t_ast *curr_data)
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

int	ft_init_streams(t_ast *pipeline_seq)
{
	t_ast	*curr_smpl_cmd;
	t_ast	*curr_data;
	t_ast	*prev_data;

	curr_smpl_cmd = pipeline_seq->node.pipe.dir.bottom;
	prev_data = NULL;
	while (curr_smpl_cmd)
	{
		expand_curr_cmd(curr_smpl_cmd);
		curr_data = curr_smpl_cmd->node.dir.bottom;
		curr_data->node.data.in_fd = 0;
		curr_data->node.data.out_fd = 1;
		if (handle_redirections(curr_data))
			return (1);
		if (prev_data)
			ft_init_pipe(curr_data, prev_data);
		prev_data = curr_data;
		curr_smpl_cmd = curr_smpl_cmd->node.dir.next;
	}
	return (0);
}

t_data	get_data(t_ast *smpl_cmd, t_ast *pipseq)
{
	t_ast	*curr_data;
	t_data	data;

	curr_data = smpl_cmd->node.dir.bottom;
	data.prev = smpl_cmd->node.data.prev_errnum;
	data.argv = curr_data->node.data.args_vec.elements;
	data.argc = curr_data->node.data.args_vec.used_size;
	data.pipes = pipseq->node.pipe.pipes_count;
	data.pids = pipseq->node.pipe.pids;
	data.out_fd = &curr_data->node.data.out_fd;
	data.in_fd = &curr_data->node.data.in_fd;
	data.redirs = pipseq->node.data.redirections;
	data.curr_data = curr_data;
	data.pip_seq = pipseq;
	return (data);
}

void	ft_fork_processes(t_ast *curr_simple_cmd, t_ast *pipeline_seq)
{
	t_data	data;
	int		i;

	data = get_data(curr_simple_cmd, pipeline_seq);
	if (!data.pipes && ft_isbuiltin(data.argv[0]))
		ft_exec(&data);
	else
	{
		i = 0;
		while (curr_simple_cmd)
		{
			data = get_data(curr_simple_cmd, pipeline_seq);
			data.pids[i] = fork();
			if (data.pids[i] == 0)
			{
				child_signals();
				ft_exec(&data);
			}
			i++;
			curr_simple_cmd = curr_simple_cmd->node.dir.next;
		}
		wait_for_children(pipeline_seq);
	}
}

void	execute_line(t_ast *ast)
{
	t_ast		*curr_pipeline_seq;
	t_ast		*curr_simple_cmd;
	static int	prev_err_num = 0;

	curr_pipeline_seq = ast->node.dir.bottom;
	while (curr_pipeline_seq)
	{
		main_signals();
		curr_pipeline_seq->node.pipe.og_in = dup(0);
		curr_pipeline_seq->node.pipe.og_out = dup(1);
		if (ft_init_streams(curr_pipeline_seq))
			break ;
		curr_pipeline_seq->node.pipe.pids = malloc(
				(curr_pipeline_seq->node.pipe.pipes_count + 1) * sizeof(int));
		curr_simple_cmd = curr_pipeline_seq->node.pipe.dir.bottom;
		curr_simple_cmd->node.data.prev_errnum = prev_err_num;
		ft_fork_processes(curr_simple_cmd, curr_pipeline_seq);
		free(curr_pipeline_seq->node.pipe.pids);
		dup2(curr_pipeline_seq->node.pipe.og_in, 0);
		dup2(curr_pipeline_seq->node.pipe.og_out, 1);
		curr_pipeline_seq = curr_pipeline_seq->node.pipe.dir.next;
	}
	prev_err_num = g_vars.last_err_num;
}

void	initialize_main_vars(t_main_data *main_vars)
{
	main_vars->ast = NULL;
	main_vars->line = NULL;
	main_vars->prompt = NULL;
	main_vars->tokens_list = NULL;
}

int	main(int argc, char **argv, char **env)
{
	t_main_data	main_vars;

	initialize_main_vars(&main_vars);
	if (argc == 1)
	{
		(void)argv;
		g_vars.last_err_num = 0;
		create_env_table(&g_vars.env_table, env);
		while (1337)
		{
			main_vars.prompt = get_prompt_name();
			main_vars.line = read_line(main_vars.prompt);
			line_tokenization(main_vars.line, &main_vars.tokens_list);
			if (check_tokens_syntax(main_vars.tokens_list) == ERROR)
			{
				free_main_allocated_memory(&main_vars);
				continue ;
			}
			create_abstract_syntax_tree(&main_vars.ast, main_vars.tokens_list);
			execute_line(main_vars.ast);
			free_main_allocated_memory(&main_vars);
		}
	}
	return (0);
}
