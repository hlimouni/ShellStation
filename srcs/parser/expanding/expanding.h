/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanding.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:39:07 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/23 09:05:33 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDING_H
# define EXPANDING_H

# include "../parser.h"

typedef struct s_expnd_vars
{
	t_char_vec	arg_vec;
	t_quotes	quotes;
}	t_expnd_vars;

char	*get_dollar_value(char *name);
void	expand_dollar_vars(char **str_addr);
void	remove_special_quotes(char **str_addr);
void	give_quotes_special_meaning(char *str);
char	*get_dollar_name(char *str, int *index_addr);
void	split_element_to_args(t_str_vec *vec, int *index);
int		expand_quoted_var(char *str, int *i, t_char_vec *vec);
int		expand_unquoted_var(char *str, int *i, t_char_vec *vec);

#endif
