/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dollar_name.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 21:47:00 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/19 11:25:30 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./expanding.h"

static int	calculate_len_of_dollar_name(char *str, int i)
{
	int		len;

	len = 0;
	if (ft_isdigit(str[i]) || str[i] == '?')
	{
		i++;
		len++;
	}
	else
	{
		while (str[i] != '\0'
			&& (ft_isalpha(str[i]) || ft_isdigit(str[i]) || str[i] == '_'))
		{
			i++;
			len++;
		}
	}
	return (len);
}

char	*get_dollar_name(char *str, int *index_addr)
{
	int		len;
	int		start;
	char	*name;

	name = NULL;
	start = *index_addr + 1;
	len = calculate_len_of_dollar_name(str, start);
	if (len > 0)
	{
		name = ft_substr(str, start, len);
		*index_addr = start + len;
	}
	return (name);
}
