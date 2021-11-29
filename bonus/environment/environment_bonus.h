/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:46:10 by iltafah           #+#    #+#             */
/*   Updated: 2021/11/10 20:26:41 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_BONUS_H
# define ENVIRONMENT_BONUS_H
# include "stdlib.h"
# include "../vectors/vectors_bonus.h"
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

#endif
