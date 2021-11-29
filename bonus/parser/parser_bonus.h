/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:35:51 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:04:31 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_BONUS_H
# define PARSER_BONUS_H

# define BOTTOM 0
# define NEXT 1

# define FALSE 0
# define TRUE 1

# define OPEND 1
# define CLOSED 0

# define NONE 0
# define EXIST 1

# define ERROR -1
# define VALID 1

# define DOUBLE_QUOTES '"'
# define SINGLE_QUOTES '\''
# define BACKSLASH '\\'
# define PIPE '|'
# define SEMICOLON ';'
# define DOLLAR '$'

# define CYN "\e[1;96m"
# define YEL "\e[1;93m"
# define RED "\e[1;91m"
# define GRN "\e[1;92m"
# define PRP "\e[1;95m"
# define WHT "\e[1;97m"

# include "stdio.h"
# include "../libft/libft.h"
# include "./parser_typedefs_bonus.h"
# include "../minishell_bonus.h"
# include "./usefull_functions/usefull_functions_bonus.h"
# include "./expanding/expanding_bonus.h"
# include "./tokenization/tokenization_bonus.h"
# include "./check_tokens_syntax/check_tokens_syntax_bonus.h"
# include "./create_abstract_syntax_tree/create_abstract_syntax_tree_bonus.h"

int		check_tokens_syntax(t_tokens *tokens_list);
void	line_tokenization(char *line, t_tokens **tokens_list);
void	create_abstract_syntax_tree(t_ast **ast, t_tokens *tokens);
int		expand_curr_cmd(t_ast *curr_simple_cmd);

#endif
