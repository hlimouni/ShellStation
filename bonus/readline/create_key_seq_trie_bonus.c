/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_key_seq_trie_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:48:00 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:11:57 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./readline_bonus.h"

t_trie_node	*get_trie_node(void)
{
	t_trie_node	*new_node;
	int			index;

	index = 0;
	new_node = malloc(sizeof(t_trie_node));
	new_node->key = none;
	new_node->children = malloc(sizeof(t_trie_node) * 128);
	while (index < 128)
		new_node->children[index++] = NULL;
	return (new_node);
}

void	insert_key(t_trie_node *trie_root, char *key_seq, int key_type)
{
	t_trie_node	*curr_node;
	int			node_index;
	int			i;

	i = 0;
	curr_node = trie_root;
	while (key_seq[i] != '\0')
	{
		node_index = (int)key_seq[i];
		if (curr_node->children[node_index] == NULL)
		{
			curr_node->children[node_index] = get_trie_node();
		}
		curr_node = curr_node->children[node_index];
		i++;
	}
	curr_node->key = key_type;
}

int	get_key(t_trie_node *trie_root, char c)
{
	static t_trie_node	*curr_node = NULL;
	int					key;

	key = none;
	if ((int)c < 0)
		return (none);
	if (curr_node == NULL)
		curr_node = trie_root;
	curr_node = curr_node->children[(int)c];
	if (curr_node != NULL)
	{
		key = curr_node->key;
		if (key == none)
			key = waiting;
		else
			curr_node = NULL;
	}
	return (key);
}

void	insert_printable_characters(t_trie_node *trie_root)
{
	static char	printable_char[] = "\0";
	static int	curr_printable_char = 32;
	static int	last_printable_char = 127;

	while (curr_printable_char <= last_printable_char)
	{
		printable_char[0] = curr_printable_char;
		insert_key(trie_root, printable_char, printable);
		curr_printable_char++;
	}
}

t_trie_node	*initialize_key_seq_trie(void)
{
	t_trie_node	*trie_root;

	trie_root = get_trie_node();
	insert_printable_characters(trie_root);
	insert_key(trie_root, "\e[A", up_arrow);
	insert_key(trie_root, "\e[B", down_arrow);
	insert_key(trie_root, "\e[C", right_arrow);
	insert_key(trie_root, "\e[D", left_arrow);
	insert_key(trie_root, "\177", backspace);
	insert_key(trie_root, "\e[H", home);
	insert_key(trie_root, "\e[F", end);
	insert_key(trie_root, "\e[1;5A", ctl_up_arrow);
	insert_key(trie_root, "\e[1;5B", ctl_down_arrow);
	insert_key(trie_root, "\e[1;5C", ctl_right_arrow);
	insert_key(trie_root, "\e[1;5D", ctl_left_arrow);
	insert_key(trie_root, "\e[1;2C", shift_right_arrow);
	insert_key(trie_root, "\e[1;2D", shift_left_arrow);
	insert_key(trie_root, "\023", ctl_s);
	insert_key(trie_root, "\026", ctl_v);
	insert_key(trie_root, "\030", ctl_x);
	insert_key(trie_root, "\04", ctl_d);
	insert_key(trie_root, "\n", enter);
	insert_key(trie_root, "\t", tab);
	return (trie_root);
}
