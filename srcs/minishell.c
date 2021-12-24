/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 00:34:20 by hlimouni          #+#    #+#             */
/*   Updated: 2021/12/24 13:48:51 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

static int	init_streams(t_ast *pipeline_seq)
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
			init_pipe(curr_data, prev_data);
		prev_data = curr_data;
		curr_smpl_cmd = curr_smpl_cmd->node.dir.next;
	}
	return (0);
}

static void	ft_fork_processes(t_ast *curr_simple_cmd, t_ast *pipeline_seq)
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

static void	execute_line(t_ast *ast)
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
		if (init_streams(curr_pipeline_seq))
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

static void	initialize_main_vars(t_main_data *main_vars)
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
