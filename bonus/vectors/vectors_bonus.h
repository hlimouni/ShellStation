/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:42:39 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:04:03 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORS_BONUS_H
# define VECTORS_BONUS_H
# include "stdlib.h"

/*
** ************************************************************************** **
								string vector
** ************************************************************************** **
*/

typedef struct s_str_vec		t_str_vec;

struct s_str_vec
{
	char	**elements;
	int		size;
	int		used_size;
	int		last_index;
	void	(*add_new_element)(t_str_vec *, char *);
	void	(*add_new_element_at_index)(t_str_vec *, char *, int);
	void	(*replace_element_at_index)(t_str_vec *, char *, int);
	void	(*delete_element_at_index)(t_str_vec *, int);
	void	(*free)(t_str_vec *);	
};

/*
** ************************************************************************** **
								char vector
** ************************************************************************** **
*/

typedef struct s_char_vec		t_char_vec;

struct s_char_vec
{
	char	*elements;
	int		size;
	int		used_size;
	int		last_index;
	void	(*add_new_element)(t_char_vec *, char);
	void	(*add_set_of_elements)(t_char_vec *, char*);
	void	(*add_new_element_at_index)(t_char_vec *, char, int);
	void	(*add_set_of_elements_at_index)(t_char_vec *, char *, int);
	void	(*replace_element_at_index)(t_char_vec *, char, int);
	void	(*delete_element_at_index)(t_char_vec *, int);
	void	(*free)(t_char_vec *);
};

/*
** ************************************************************************** **
							vector of char vectors
** ************************************************************************** **
*/

typedef struct s_vec_vec_char	t_vchar_vec;

struct s_vec_vec_char
{
	t_char_vec	*elements;
	int			size;
	int			used_size;
	int			last_index;
	void		(*add_new_element)(t_vchar_vec *, t_char_vec);
	void		(*add_new_element_at_index)(t_vchar_vec *, t_char_vec, int);
	void		(*delete_element_at_index)(t_vchar_vec *, int);
	void		(*delete_last_element)(t_vchar_vec *);
	void		(*free)(t_vchar_vec *);
};

/*
** ************************************************************************** **
								  int vector
** ************************************************************************** **
*/

typedef struct s_int_vec		t_int_vec;

struct s_int_vec
{
	int		*elements;
	int		size;
	int		used_size;
	int		last_index;
	void	(*add_new_element)(t_int_vec *, int);
	void	(*add_new_element_at_index)(t_int_vec *, int, int);
	void	(*replace_element_at_index)(t_int_vec *, int, int);
	void	(*delete_element_at_index)(t_int_vec *, int);
	void	(*push_element)(t_int_vec *, int);
	void	(*pop_element)(t_int_vec *, int *);
	void	(*free)(t_int_vec *);
};

/*
** ************************************************************************** **
*/

void	initialize_vec_content(t_str_vec *vec);
void	add_new_element(t_str_vec *vec, char *element);
void	add_new_element_at_index(t_str_vec *vec, char *element, int index);
void	replace_element_at_index(t_str_vec *vec, char *element, int index);
void	delete_element_at_index(t_str_vec *vec, int index);
void	vector_free(t_str_vec *vec);
void	realloc_vector(t_str_vec *vec);

void	initialize_vec_of_char(t_char_vec *vec);
void	realloc_char_vector(t_char_vec *vec, int new_size);
void	add_new_char(t_char_vec *vec, char c);
void	add_set_of_chars(t_char_vec *vec, char *str);
void	add_new_char_at_index(t_char_vec *vec, char c, int index);
void	add_set_of_chars_at_index(t_char_vec *vec, char *str, int index);
void	delete_char_at_index(t_char_vec *vec, int index);
void	replace_char_at_index(t_char_vec *vec, char c, int index);
void	char_vector_free(t_char_vec *vec);

void	initialize_vec_of_char_vec(t_vchar_vec *vec);
void	add_new_char_vec(t_vchar_vec *vec, t_char_vec element);
void	add_new_char_vec_at_index(t_vchar_vec *vec, t_char_vec elem, int index);
void	char_vec_vector_free(t_vchar_vec *vec);
void	delete_char_vec_at_index(t_vchar_vec *vec, int index);
void	delete_last_char_vec(t_vchar_vec *vec);
void	realloc_vector_of_char_vec(t_vchar_vec *vec);
void	char_vec_vector_free(t_vchar_vec *vec);

void	initialize_vec_of_int(t_int_vec *vec);
void	realloc_int_vector(t_int_vec *vec, int new_size);
void	add_new_int(t_int_vec *vec, int num);
void	delete_int_at_index(t_int_vec *vec, int index);
void	add_new_int_at_index(t_int_vec *vec, int num, int index);
void	replace_int_at_index(t_int_vec *vec, int num, int index);
void	int_vector_free(t_int_vec *vec);
void	push_int(t_int_vec *vec, int num);
void	pop_int(t_int_vec *vec, int *num_addr);

#endif