/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull_functions_typedefs_bonus.h                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:22:20 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:04:39 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USEFULL_FUNCTIONS_TYPEDEFS_BONUS_H
# define USEFULL_FUNCTIONS_TYPEDEFS_BONUS_H

typedef struct s_quotes
{
	int		backslash;
	int		pipe;
	int		semicolon;
	int		double_quotes;
	int		single_quotes;
	int		old_state;
	int		curr_state;
}	t_quotes;

#endif