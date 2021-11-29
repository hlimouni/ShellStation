/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:47:43 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:11:46 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./readline_bonus.h"

void	initialize_tty_device(t_rdline *rdl_vars)
{
	int		std_fd;
	char	*tty_name;

	if (isatty(STDIN_FILENO))
		std_fd = STDIN_FILENO;
	else
		exit(0);
	tty_name = ttyname(std_fd);
	rdl_vars->tty_fd = open(tty_name, O_WRONLY);
}

void	initialize_termios_struct(struct termios *original_termios_state)
{
	char		*term_type;

	term_type = getenv("TERM");
	if (term_type == NULL)
		term_type = "xterm-256color";
	tgetent(NULL, term_type);
	tcgetattr(g_vars.rdl_vars.tty_fd, original_termios_state);
}

void	initialize_capabilities(t_capability *capability)
{
	capability->mv_cursor_up_vertically = tgetstr("up", NULL);
	capability->mv_cursor_down_vertically = tgetstr("do", NULL);
	capability->mv_cursor_left = tgetstr("le", NULL);
	capability->mv_cursor_right = tgetstr("nd", NULL);
	capability->mv_cursor_to_colm = tgetstr("ch", NULL);
	capability->clear_line_after_cursor = tgetstr("ce", NULL);
	capability->clear_lines_below = tgetstr("cd", NULL);
	capability->make_cursor_invisible = tgetstr("vi", NULL);
	capability->return_cursor_to_normal = tgetstr("ve", NULL);
	capability->enter_standout_mode = tgetstr("so", NULL);
	capability->leave_standout_mode = tgetstr("se", NULL);
}

void	initialize_rdl_vars_second_part(t_rdline *rdl_vars)
{
	rdl_vars->reverse_video_mode = 0;
	rdl_vars->reverse_video_mode = 0;
	rdl_vars->curr_hilitd_char_index = 0;
	rdl_vars->starting_hilitd_colm = 0;
	rdl_vars->starting_hilitd_row = 0;
	rdl_vars->starting_hilitd_index = 0;
	rdl_vars->beg_hilitd_index = 0;
	rdl_vars->last_hilitd_index = 0;
	rdl_vars->previous_key = 0;
	rdl_vars->tab_mode = 0;
	rdl_vars->hilitd_txt = NULL;
	rdl_vars->line = NULL;
	rdl_vars->prompt = NULL;
	rdl_vars->old_history = NULL;
}

void	initialize_rdl_vars(t_rdline *rdl_vars)
{
	rdl_vars->tty_fd = 0;
	rdl_vars->syntax_highlighting = 0;
	rdl_vars->auto_suggestions = 0;
	rdl_vars->c_i = 0;
	rdl_vars->l_i = 0;
	rdl_vars->curs_row_pos = 0;
	rdl_vars->curs_colm_pos = 0;
	rdl_vars->prompt_len = 0;
	rdl_vars->printed_lines = 0;
	rdl_vars->width_of_screen = 0;
	rdl_vars->matched_history_index = 0;
	rdl_vars->is_matched_history = 0;
	initialize_rdl_vars_second_part(rdl_vars);
	rdl_vars->key_seq_trie = initialize_key_seq_trie();
	initialize_tab_vars(&rdl_vars->tab_vars);
	initialize_vec_of_char_vec(&rdl_vars->history_vec);
	initialize_vec_of_int(&rdl_vars->old_curs_colm_pos_stack);
	initialize_vec_of_int(&rdl_vars->old_curs_row_pos_stack);
}
