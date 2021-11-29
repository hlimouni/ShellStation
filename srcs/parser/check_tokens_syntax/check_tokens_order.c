/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tokens_order.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:34:24 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/11 15:51:00 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_tokens_syntax.h"

void	check_pipe_token_order(t_vars *vars)
{
	if (vars->command == NONE)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `|'\n",
			STDERR_FILENO);
		vars->error = EXIST;
		g_vars.last_err_num = 258;
	}
	remember_last_token(vars, e_pipe);
}

void	check_semicolon_token_order(t_vars *vars)
{
	if (vars->command == NONE)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `;'\n",
			STDERR_FILENO);
		vars->error = EXIST;
		g_vars.last_err_num = 258;
	}
	remember_last_token(vars, e_semicolon);
}

void	check_redirection_token_order(t_vars *vars, int type)
{
	char	*redir;

	redir = NULL;
	if (vars->redirection == EXIST)
	{
		if (type == less)
			redir = "`<'\n";
		else if (type == great)
			redir = "`>'\n";
		else if (type == double_great)
			redir = "`>>'\n";
		else if (type == double_less)
			redir = "`<<'\n";
		ft_putstr_fd("minishell: syntax error near unexpected token ",
			STDERR_FILENO);
		ft_putstr_fd(redir, STDERR_FILENO);
		vars->error = EXIST;
		g_vars.last_err_num = 258;
	}
	remember_last_token(vars, type);
}

void	check_newline_token_order(t_vars *vars)
{
	if (vars->redirection == EXIST)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `newline'\n",
			STDERR_FILENO);
		vars->error = EXIST;
		g_vars.last_err_num = 258;
	}
	else if (vars->pipe == EXIST)
	{
		ft_putstr_fd("minishell: multiline commands not allowed\n",
			STDERR_FILENO);
		vars->error = EXIST;
		g_vars.last_err_num = 258;
	}
}

void	check_word_token_order(t_vars *vars, char *token)
{
	check_simple_word_syntax(token, vars);
	remember_last_token(vars, e_simple_word);
}
