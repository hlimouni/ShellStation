/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 16:40:58 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:11:35 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./readline_bonus.h"

void	set_rdl_vars(t_rdline *rdl_vars, char *prompt)
{
	t_vchar_vec		*history_vec;

	history_vec = &rdl_vars->history_vec;
	rdl_vars->old_history = convert_history_vec_to_array(history_vec);
	add_empty_char_vec_to_history_vec(history_vec);
	rdl_vars->prompt = prompt;
	if (prompt == NULL)
		rdl_vars->prompt_len = 0;
	else
		rdl_vars->prompt_len = ft_strlen_utf8(rdl_vars->prompt);
	rdl_vars->width_of_screen = get_screen_width();
	rdl_vars->c_i = 0;
	rdl_vars->l_i = history_vec->last_index;
	rdl_vars->curs_row_pos = 0;
	rdl_vars->curs_colm_pos = rdl_vars->prompt_len;
}

int	which_prototype(int key)
{
	if (key >= up_arrow && key <= tab)
		return (first);
	else if (key == printable)
		return (second);
	return (none);
}

void	call_suitable_func(t_func_ptr *func, t_rdline *rdl_v, int key, char c)
{
	int	proto_type;

	proto_type = which_prototype(key);
	if (proto_type == first)
		func[key].first(rdl_v);
	else if (proto_type == second)
		func[key].second(rdl_v, c);
}

void	start_key_action(t_rdline *rdl_vars, int key, char c)
{
	static t_func_ptr	func_ptrs[22] = {
		{NULL}, {NULL},
		{.first = start_up_arrow_action},
		{.first = start_down_arrow_action},
		{.first = start_left_arrow_action},
		{.first = start_right_arrow_action},
		{.first = start_enter_action},
		{.first = start_backspace_action},
		{.first = start_home_action},
		{.first = start_end_action},
		{.first = start_shift_right_arrow_action},
		{.first = start_shift_left_arrow_action},
		{.first = start_ctl_up_arrow_action},
		{.first = start_ctl_down_arrow_action},
		{.first = start_ctl_right_arrow_action},
		{.first = start_ctl_left_arrow_action},
		{.first = start_ctl_s_action},
		{.first = start_ctl_v_action},
		{.first = start_ctl_x_action},
		{.first = exit_program},
		{.first = start_tab_action},
		{.second = start_printable_action}
	};

	call_suitable_func(func_ptrs, rdl_vars, key, c);
}

void	process_input(t_rdline *rdl_vars, char *prompt)
{
	int		key;
	char	c;

	key = none;
	set_rdl_vars(rdl_vars, prompt);
	print_prompt(rdl_vars);
	while (read(STDIN_FILENO, &c, 1))
	{
		key = get_key(rdl_vars->key_seq_trie, c);
		if (key == none || key == waiting)
			SKIP ;
		start_key_action(rdl_vars, key, c);
		if (key == enter && rdl_vars->previous_key != disable_enter)
			break ;
	}
	free_array(&rdl_vars->old_history);
}
