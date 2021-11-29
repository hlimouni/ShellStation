/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 08:27:58 by iariss            #+#    #+#             */
/*   Updated: 2021/07/17 12:05:48 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell_bonus.h"

void	child_dup(t_piping *num, t_ast *curr_simple_cmd)
{
	if (curr_simple_cmd->node.dir.next)
		dup2(num->p[num->pipe_index + 1], 1);
	if (num->pid_index != 0)
		dup2(num->p[num->pipe_index - 2], 0);
}

void	loop_w_pipe(t_piping *num, t_ast *curr_simple_cmd, t_ast *pipeline_seq)
{
	t_ast	*curr_data;

	while (curr_simple_cmd)
	{
		num->pid[num->pid_index] = fork();
		if (num->pid[num->pid_index] == 0)
		{
			signal(SIGQUIT, handle_child_quit);
			signal(SIGINT, handle_child_c);
			child_dup(num, curr_simple_cmd);
			num->i = 0;
			while (num->i < (num->num_pipes * 2))
			{
				close(num->p[num->i]);
				num->i++;
			}
			expand_curr_cmd(curr_simple_cmd);
			curr_data = curr_simple_cmd->node.dir.bottom;
			execution(curr_data);
			exit(g_vars.last_err_num);
		}
		curr_simple_cmd = get_curr_smpl_cmd_node(pipeline_seq);
		num->pipe_index += 2;
		num->pid_index++;
	}
}

void	start_execution(t_ast *ast)
{
	t_ast		*curr_pipeline_seq;
	t_ast		*curr_simple_cmd;
	t_piping	num;

	curr_pipeline_seq = get_curr_pipeline_seq_node(ast);
	while (curr_pipeline_seq)
	{
		signal(SIGQUIT, handle_quit);
		signal(SIGINT, handle_c);
		curr_simple_cmd = get_curr_smpl_cmd_node(curr_pipeline_seq);
		num.num_pipes = curr_pipeline_seq->node.pipe.pipes_count;
		if (num.num_pipes)
		{
			allocate_startp(&num);
			loop_w_pipe(&num, curr_simple_cmd, curr_pipeline_seq);
			wait_cloce_free(num);
		}
		else
			without_pipes(curr_simple_cmd, num, curr_pipeline_seq);
		curr_pipeline_seq = get_curr_pipeline_seq_node(ast);
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
