/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline_typedefs.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:47:17 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/09 12:14:38 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_TYPEDEFS_H
# define READLINE_TYPEDEFS_H

# include "../vectors/vectors.h"
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <termcap.h>
# include <termios.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <dirent.h>

typedef enum e_key
{
	none,
	waiting,
	up_arrow,
	down_arrow,
	left_arrow,
	right_arrow,
	enter,
	backspace,
	home,
	end,
	shift_right_arrow,
	shift_left_arrow,
	ctl_up_arrow,
	ctl_down_arrow,
	ctl_right_arrow,
	ctl_left_arrow,
	ctl_s,
	ctl_v,
	ctl_x,
	ctl_d,
	tab,
	printable,
	disable_enter
}	t_key;

typedef enum e_prototype {first, second}	t_prototype;

typedef struct s_trie_node
{
	struct s_trie_node	**children;
	t_key				key;
}				t_trie_node;

typedef struct s_tab_vars
{
	int			curr_index;
	int			max_file_case_len;
	char		*dir_to_search;
	char		*file_to_match;
	t_str_vec	matched_files;
	int			printd_matched_file_len;
}				t_tab_vars;

typedef struct s_capability
{
	char		*mv_cursor_down_vertically;
	char		*mv_cursor_up_vertically;
	char		*mv_cursor_left;
	char		*mv_cursor_right;
	char		*mv_cursor_to_colm;
	char		*clear_line_after_cursor;
	char		*clear_lines_below;
	char		*make_cursor_invisible;
	char		*return_cursor_to_normal;
	char		*leave_standout_mode;
	char		*enter_standout_mode;
}				t_capability;

typedef struct s_rdline
{
	t_capability	capability;
	t_trie_node		*key_seq_trie;
	t_vchar_vec		history_vec;
	t_tab_vars		tab_vars;
	struct termios	original_termios_state;
	char			**old_history;
	char			*line;
	char			*prompt;
	int				tty_fd;
	int				prompt_len;
	int				curs_colm_pos;
	int				curs_row_pos;
	t_int_vec		old_curs_colm_pos_stack;
	t_int_vec		old_curs_row_pos_stack;
	int				printed_lines;
	int				width_of_screen;
	int				l_i;
	int				c_i;
	int				reverse_video_mode;
	char			*hilitd_txt;
	int				is_matched_history;
	int				matched_history_index;
	int				starting_hilitd_index;
	int				curr_hilitd_char_index;
	int				beg_hilitd_index;
	int				last_hilitd_index;
	int				starting_hilitd_colm;
	int				starting_hilitd_row;
	int				syntax_highlighting;
	int				auto_suggestions;
	int				previous_key;
	int				tab_mode;
}					t_rdline;

typedef union u_func_ptr
{
	void	(*first)(t_rdline *rdl_vars);
	void	(*second)(t_rdline *rdl_vars, char c);
}				t_func_ptr;

#endif
