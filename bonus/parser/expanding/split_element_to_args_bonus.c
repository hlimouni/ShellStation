/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_element_to_args_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:39:22 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:10:36 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./expanding_bonus.h" 

void	get_splitted_arg_and_insert_it(char **arg, t_str_vec *args_vec, int i)
{
	t_char_vec	splitted_arg;
	int			backslash;

	initialize_vec_of_char(&splitted_arg);
	while ((**arg != ' ' || backslash == EXIST) && **arg != '\0')
	{
		backslash = NONE;
		if (**arg == SP_DOUBLE_QUOTES || **arg == SP_SINGLE_QUOTES)
		{
			while (TRUE)
			{
				splitted_arg.add_new_element(&splitted_arg, **arg);
				(*arg)++;
				if (**arg == SP_DOUBLE_QUOTES || **arg == SP_SINGLE_QUOTES)
					break ;
			}
		}
		if (**arg == SP_BACKSLASH)
			backslash = EXIST;
		splitted_arg.add_new_element(&splitted_arg, **arg);
		(*arg)++;
	}
	args_vec->add_new_element_at_index(args_vec, splitted_arg.elements, i);
	remove_special_quotes(&args_vec->elements[i]);
}

void	split_element_to_args(t_str_vec *vec, int *index)
{
	int			i;
	char		*arg;

	i = *index;
	arg = vec->elements[i];
	while (*arg != '\0')
	{
		if (*arg == ' ')
			arg++;
		else
			get_splitted_arg_and_insert_it(&arg, vec, i++);
	}
	vec->delete_element_at_index(vec, i);
	*index = i;
}
