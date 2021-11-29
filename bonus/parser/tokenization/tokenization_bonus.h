/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:36:00 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/17 12:04:49 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZATION_BONUS_H
# define TOKENIZATION_BONUS_H

# include "../parser_bonus.h"

int		treat_quotes(char *line, char sd_quote);
char	*get_pipe(char **line, t_type *type);
char	*get_semicolon(char **line, t_type *type);
char	*get_redirection(char **line, t_type *type);
char	*get_simple_word(char **line, t_type *type);

#endif
