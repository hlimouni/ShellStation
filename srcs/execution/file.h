/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 21:42:28 by iariss            #+#    #+#             */
/*   Updated: 2021/11/24 16:45:59 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

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

/***********************************************************/												
/***********************************************************/

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

# define ARGC node.data.args_vec.used_size
# define ARGV node.data.args_vec.elements
# define PIPES node.pipe.pipes_count
# define FAMILY node.pipe.family
# define OUT_FD node.data.out_fd
# define IN_FD node.data.in_fd

void	ft_export(t_ast *data);
void	ft_unset(t_ast *data);
void	ft_cd(t_ast *data);
void	ft_echo(t_ast *data);
void	ft_exit(t_ast *data, int exit_num);
void	ft_exec(t_ast *data, t_ast *pipeline_seq);
void	ft_pwd(void);
void	ft_env(void);
void	free_2d_array(char ***arr);
int		ft_isbuiltin(char *builtin);

/***********************************************************/												
/***********************************************************/												

int		ft_strcmp(const char *s1, const char *s2);

#endif
