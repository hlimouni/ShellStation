/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_main_allocated_memory.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 21:48:52 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/14 21:49:07 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./freeing_time.h"

void	free_main_allocated_memory(t_main_data *main_vars)
{
	if (main_vars->line != NULL)
		free(main_vars->line);
	if (main_vars->prompt != NULL)
		free(main_vars->prompt);
	if (main_vars->tokens_list != NULL)
		free_tokens_list(&main_vars->tokens_list);
	if (main_vars->ast != NULL)
		free_abstract_syntax_tree(&main_vars->ast);
}
