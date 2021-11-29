/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tokens_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:45:53 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/13 19:45:55 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./freeing_time.h"

void	free_tokens_list(t_tokens **tokens_list)
{
	t_tokens	*curr_token;
	t_tokens	*next_token;

	curr_token = *tokens_list;
	while (curr_token)
	{
		next_token = curr_token->next;
		if (curr_token->data != NULL)
			free(curr_token->data);
		free(curr_token);
		curr_token = next_token;
	}
	*tokens_list = NULL;
}
