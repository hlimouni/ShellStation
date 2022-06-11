/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:46:10 by iltafah           #+#    #+#             */
/*   Updated: 2022/06/11 10:29:56 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H
# include "stdlib.h"
# include "../vectors/vectors.h"
# include "../libft/libft.h"
/*
** ************************************************************************** **
									env table								
** ************************************************************************** **
*/

typedef struct s_env_table
{
	t_str_vec	name;
	t_str_vec	value;
}				t_env_table;

/*
** ************************************************************************** **
*/

char	**convert_env_table_to_array(t_env_table env_table);
void	create_env_table(t_env_table *env_table, char **env);
char	*get_value_of_env_name(t_env_table env_table, char *name);
int		get_index_of_env_name(t_env_table env_table, char *name);

#endif
