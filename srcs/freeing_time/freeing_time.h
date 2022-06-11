/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_time.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:45:57 by iltafah           #+#    #+#             */
/*   Updated: 2022/06/11 10:30:07 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREEING_TIME_H
# define FREEING_TIME_H

# include "../minishell.h"

void	free_array(char ***array_addr);
void	free_abstract_syntax_tree(t_ast **ast);
void	free_tokens_list(t_tokens **tokens_list);
void	free_main_allocated_memory(t_main_data *main_vars);

#endif