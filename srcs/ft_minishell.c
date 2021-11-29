/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:34:20 by hlimouni          #+#    #+#             */
/*   Updated: 2021/11/24 18:40:08 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

t_ast	*ft_find_command(int pid, t_ast *pipeline_seq)
{
	int	i;
	t_ast	*curr_smpl_cmd;

	curr_smpl_cmd = pipeline_seq->node.pipe.dir.bottom;
	i = 0;
	while (curr_smpl_cmd)
	{
		if (pipeline_seq->FAMILY[i] == pid)
			return (curr_smpl_cmd->node.dir.bottom);
		i++;
		curr_smpl_cmd = curr_smpl_cmd->node.dir.next;
	}
	return (NULL);
}

void	handle_child_quit(int sig_num)
{
	if (sig_num == SIGQUIT)
		g_vars.last_err_num = 131;
}

void	handle_child_c(int sig_num)
{
	if (sig_num == SIGINT)
		g_vars.last_err_num = 130;
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

static int	ft_update_status(
				int terminated,
				int returned,
				t_ast	*pipeline_seq)
{
	int		signaled;
	t_ast	*curr_data;

	signaled = 0;
	if (terminated == pipeline_seq->FAMILY[pipeline_seq->PIPES])
	{
		if (!WTERMSIG(returned))
			g_vars.last_err_num = WEXITSTATUS(returned);
		else
		{
			signaled = 1;
			g_vars.last_err_num = WTERMSIG(returned) + 128;
		}
	}
	curr_data = ft_find_command(terminated, pipeline_seq);
	if (curr_data)
	{
		if (curr_data->OUT_FD != 1)
			close(curr_data->OUT_FD);
		if (curr_data->IN_FD != 0)
			close(curr_data->IN_FD);
	}
	return (signaled);
}

static void	wait_for_children(t_ast *pipeline_seq)
{
	int		i;
	int		returned;
	int		signaled;

	signaled = 0;
	i = 0;
	while (i <= pipeline_seq->PIPES)
	{
		signaled += ft_update_status(wait(&returned), returned, pipeline_seq);
		i++;
	}
	if (signaled)
	{
		if (g_vars.last_err_num == 131)
			ft_putstr_fd("Quit: 3", 1);
		ft_putstr_fd("\n", 1);
	}
}

void	ft_init_pipe(t_ast *curr_data, t_ast *prev_data)
{
	int	fd[2];

	pipe(fd);
	if (prev_data->OUT_FD != 1)
		close(fd[1]);
	else
		prev_data->OUT_FD = fd[1];
	if (curr_data->IN_FD != 0)
		close(fd[0]);
	else
		curr_data->IN_FD = fd[0];
}

int	ft_redir_file(t_ast *data, t_redirection *redirs, int open_flag)
{
	int	fd;
	char dir;

	dir = *(redirs->type);
	if (dir == '>' && data->OUT_FD != 1)
		close(data->OUT_FD);
	if (dir == '<' && data->IN_FD != 0)
		close(data->IN_FD);
	fd = open(redirs->file, open_flag, 0644);
	if (fd == -1)
	{
		perror("minishell");
		g_vars.last_err_num = 1;
		return (1);
	}
	if (dir == '>')
		data->OUT_FD = fd;
	if (dir == '<')
		data->IN_FD = fd;
	return (0);
}

int	handle_redirections(t_ast *curr_data)
{
	t_redirection	*redirs;

	redirs = curr_data->node.data.redirections;
	while (redirs)
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
			ft_redir_file(curr_data, redirs, O_APPEND | O_WRONLY
				| O_CREAT);
		// else if (!(ft_strcmp(redirs->type, "<<")))
		// 	ft_herdoc(curr_data, redirs);
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
		curr_data->IN_FD = 0;
		curr_data->OUT_FD = 1;
		if (handle_redirections(curr_data))
			return (1);
		if (prev_data)
			ft_init_pipe(curr_data, prev_data);
		prev_data = curr_data;
		curr_smpl_cmd = curr_smpl_cmd->node.dir.next;
	}
	return (0);
}

// void	child_dup(t_piping *num, t_ast *curr_simple_cmd)
// {
// 	if (curr_simple_cmd->node.dir.next)
// 		dup2(num->p[num->pipe_index + 1], 1);
// 	if (num->pid_index != 0)
// 		dup2(num->p[num->pipe_index - 2], 0);
// }

void	ft_fork_processes(t_ast *curr_simple_cmd, t_ast *pipeline_seq)
{
	t_ast	*curr_data;
	int		i;

	curr_data = curr_simple_cmd->node.dir.bottom;
	if (!pipeline_seq->PIPES && ft_isbuiltin(curr_data->ARGV[0]))
		ft_exec(curr_data, pipeline_seq);
	else
	{
		i = 0;
		while (curr_simple_cmd)
		{
			pipeline_seq->FAMILY[i] = fork();
			if (pipeline_seq->FAMILY[i] == 0)
			{
				signal(SIGQUIT, handle_child_quit);
				signal(SIGINT, handle_child_c);
				curr_data = curr_simple_cmd->node.dir.bottom;
				ft_exec(curr_data, pipeline_seq);
			}
			i++;
			curr_simple_cmd = curr_simple_cmd->node.dir.next;
		}
		wait_for_children(pipeline_seq);
	}
}

void	start_execution(t_ast *ast)
{
	t_ast		*curr_pipeline_seq;
	t_ast		*curr_simple_cmd;
	int			pipes;

	curr_pipeline_seq = ast->node.dir.bottom;
	while (curr_pipeline_seq)
	{
		signal(SIGQUIT, handle_quit);
		signal(SIGINT, handle_c);
		pipes = curr_pipeline_seq->PIPES;
		if (ft_init_streams(curr_pipeline_seq))
			return ;//streams
		curr_pipeline_seq->FAMILY = ft_calloc(pipes + 1, sizeof(int));
		curr_simple_cmd = curr_pipeline_seq->node.pipe.dir.bottom;
		// if (curr_simple_cmd == NULL)
		// 	return ;
		ft_fork_processes(curr_simple_cmd, curr_pipeline_seq);
		free(curr_pipeline_seq->FAMILY);
		curr_pipeline_seq = curr_pipeline_seq->node.pipe.dir.next;
	}
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
			start_execution(main_vars.ast);
			free_main_allocated_memory(&main_vars);
		}
	}
	return (0);
}
