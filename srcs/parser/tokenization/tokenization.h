/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenization.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:36:00 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/15 17:36:10 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZATION_H
# define TOKENIZATION_H

# include "../parser.h"

int		treat_quotes(char *line, char sd_quote);
char	*get_pipe(char **line, t_type *type);
char	*get_semicolon(char **line, t_type *type);
char	*get_redirection(char **line, t_type *type);
char	*get_simple_word(char **line, t_type *type);

#endif
