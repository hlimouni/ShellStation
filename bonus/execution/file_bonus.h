/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 21:42:28 by iariss            #+#    #+#             */
/*   Updated: 2021/07/17 12:05:24 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_BONUS_H
# define FILE_BONUS_H

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
# include "../minishell_bonus.h"
# include <signal.h>
# include <sys/stat.h> 
# include "../parser/parser_typedefs_bonus.h"

typedef struct s_env
{
	char	**names;
	char	**values;
	char	**env;
}				t_env;

typedef struct s_varso
{
	char	*prev_path;
	t_env	export;
	int		cursed;
}				t_varso;

typedef struct s_args
{
	int		pipe;
	int		semi;
	char	*command;
	char	**flags;
}				t_args;

typedef struct s_rand
{
	int			i;
	int			x;
	char		**tab;
	int			y;
	char		*sticker;
	struct stat	buff;
	int			status;
	pid_t		pid;
	int			command_exists;
}				t_rand;

typedef struct s_expo_vars
{
	int		i;
	int		j;
	int		x;
	char	*smallest;
	int		k;
	char	*subbed;
}				t_expo_vars;

typedef struct s_unset_vars
{
	int		x;
	int		i;
	char	**a;
}				t_unset_vars;

typedef struct s_exv_vars
{
	char		*path;
	char		cwd[PATH_MAX];
	int			y;
	int			i;
	pid_t		pid;
	int			status;
	struct stat	buff;
}				t_exv_vars;

typedef struct s_redirection_vars
{
	int				fd;
	int				dep;
	t_data_content	head;
	char			*input;
	char			*all;
	int				x;
	int				dupp;
	int				out;
	int				*p;
}				t_redirection_vars;

char	*find_env(char *targ);
void	export(char **args, t_varso *vars, t_ast *sim_cmd_nd);
int		ft_strcmp(const char *s1, const char *s2);
char	*find_home(void);
void	cd(char **args, t_varso *vars);
void	change_value(char *name, char *new_value);
void	check_path(char **path, int *f);
void	echo(char **v);
int		check_echo(char **v);
void	swap_values(char **s1, char **s2);
void	sort_expo(t_varso *vars);
void	empty_expo(t_varso *vars);
void	add_to_vars(char *add, int x);
void	unset(t_ast *scn);
void	enviro(void);
void	exv(t_ast *scn, t_varso *vars);
void	add_one(t_varso *vars);
void	merge_env(t_varso *vars);
int		check_redis(t_ast *scn);
void	ft_printf_string(char *s);
void	error_msg(char *s);
void	check_exit(t_ast *scn, int x);
int		check_exit_num(char *num, int j);
void	builtins(t_ast *scn, t_varso *vars);
void	pwd(void);
void	handle_c(int sig_num);
void	handle_quit(int sig_num);
int		ft_strcmp(const char *s1, const char *s2);
char	*join_free(char *s1, char *s2, int index);
void	add_one(t_varso *vars);
int		check_command(t_ast *scn, char *sticker, t_varso *vars, t_rand *num);
void	execv_errors(t_rand *num, t_ast *scn, struct stat buff);
void	print_expo(t_varso *vars, t_expo_vars *exp);
void	export_add(char **args, int lp, int x);
void	normal_expo(char **args, int lp, int x);
void	swap_values(char **s1, char **s2);
void	export_add_vars(t_ast *scn, char **args);
int		check_args2(int lp, char **a);
int		check_args(char **a, int lp);
void	execv_main_loop(t_rand *num, t_ast *scn, t_varso *vars);
void	ex(t_rand *num, t_varso *vars, t_ast *scn);
void	print_error(char *s);
void	print_three(char *s1, char *s2, char *s3);
void	with_path(char *path, t_varso *vars, t_ast *scn);
void	free_vars(t_rand num, t_varso *vars);
void	execute_path(int *y, t_ast *scn, t_varso *vars);
void	without_path_slash(t_varso *vars, t_ast *scn);
void	status_check_w_err(t_rand *num, t_ast *scn, struct stat buff);
void	status_check(t_redirection_vars *red);

#endif
