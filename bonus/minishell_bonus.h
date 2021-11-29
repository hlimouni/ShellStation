/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:45:07 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:03:49 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BONUS_H
# define MINISHELL_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/termios.h>
# include <sys/ioctl.h>

# include "./libft/libft.h"
# include "./parser/parser_bonus.h"
# include "./execution/file_bonus.h"
# include "./vectors/vectors_bonus.h"
# include "./minishell_typedefs_bonus.h"
# include "./freeing_time/freeing_time_bonus.h"
# include "./get_next_line/get_next_line_bonus.h"

# define CYN "\e[1;96m"
# define YEL "\e[1;93m"
# define RED "\e[1;91m"
# define RED_MAX "\e[38;5;196m"
# define GRN "\e[1;92m"
# define PRP "\e[1;95m"
# define WHT "\e[1;97m"
# define GRY "\e[38;5;245m"
# define PNK "\e[38;5;200m"
# define ORN "\e[38;5;202m"
# define L_CYN "\e[38;5;159m"

enum e_bool {false, true};

extern t_gvars		g_vars;

t_gvars				g_vars;

void	execution(t_ast *scn);
char	*get_prompt_name(void);
char	*get_curr_dir_name(void);
void	handle_child_c(int sig_num);
void	wait_cloce_free(t_piping num);
void	allocate_startp(t_piping *num);
void	handle_child_quit(int sig_num);
char	*treat_heredocs(char *delimiter);
void	change_value(char *name, char *new_value);
t_ast	*get_curr_smpl_cmd_node(t_ast *pipeline_seq);
void	without_pipes(t_ast *curr_smpl_cmd, t_piping num, t_ast *pipeline_seq);
void	loop_w_pipe(t_piping *num, t_ast *curr_simple_cmd, t_ast *pipeline_seq);

#endif
