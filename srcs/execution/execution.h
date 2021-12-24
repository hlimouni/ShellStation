/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 21:42:28 by iariss            #+#    #+#             */
/*   Updated: 2021/12/24 12:53:56 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <limits.h>
# include <dirent.h>
# include "../minishell.h"
# include <signal.h>
# include <sys/stat.h> 
# include "../parser/parser_typedefs.h"
# include <sys/types.h>
# include <sys/wait.h>
# include "../vectors/vectors.h"
# include "errno.h"

enum	e_builtins
{
	__echo = 1,
	__cd,
	__pwd,
	__export,
	__unset,
	__env,
	__exit	
};
/*
# define ARGC node.data.args_vec.used_size
# define ARGV node.data.args_vec.elements
# define PIPES node.pipe.pipes_count
# define PIDS node.pipe.pids
# define OUT_FD node.data.out_fd
# define IN_FD node.data.in_fd
*/

typedef struct s_data
{
	t_ast			*pip_seq;
	int				argc;
	char			**argv;
	int				pipes;
	int				*pids;
	int				*out_fd;
	int				*in_fd;
	int				prev;
	t_ast			*curr_data;
	t_redirection	*redirs;
}				t_data;

void	ft_export(t_data *data);
void	ft_unset(t_data *data);
void	ft_cd(t_data *data);
void	ft_echo(t_data *data);
void	ft_exit(t_data *data);
void	ft_exec(t_data *data);
void	ft_pwd(void);
void	ft_env(void);
void	free_2d_array(char ***arr);
int		ft_isbuiltin(char *builtin);
void	ft_close_descriptors(t_ast *pipeline_seq);
int		ft_strcmp(const char *s1, const char *s2);
int		is_arg_valid(char *arg);
void	add_valid_env_variable(char *arg, int valid_namelen);
void	append_to_env_value(char *arg, int valid_namelen);
void	sort_env(char **name, char **value, int len);
int		ft_execbuiltin(t_data *data);
int		ft_isbuiltin(char *builtin);
int		ft_error(char *name, char *desc);
char	*get_env_value(char *name);
int		is_strint(char *str);
int		ft_strto_long(char *str, long *num);
void	main_signals(void);
void	child_signals(void);
void	wait_for_children(t_ast *pipeline_seq);
void	init_pipe(t_ast *curr_data, t_ast *prev_data);
int		handle_redirections(t_ast *curr_data);
t_data	get_data(t_ast *smpl_cmd, t_ast *pipseq);

#endif
