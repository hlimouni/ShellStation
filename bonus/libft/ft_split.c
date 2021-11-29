/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iariss <iariss@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:01:32 by iltafah           #+#    #+#             */
/*   Updated: 2021/07/02 14:57:45 by iariss           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	free_it(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

static size_t	y_tab(char const *s, char c)
{
	size_t	y_len;

	y_len = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			y_len++;
		s++;
	}
	return (y_len);
}

static size_t	x_word(char const *s, char c)
{
	size_t	x_len;

	x_len = 0;
	while (*s != c && *s)
	{
		x_len++;
		s++;
	}
	return (x_len);
}

static int	split_it(char **tab, char const *s, size_t y_len, char c)
{
	size_t	x_len;
	size_t	x;
	size_t	y;

	y = 0;
	while (y < y_len)
	{
		while ((*s == c) && *s)
			s++;
		x_len = x_word(s, c);
		tab[y] = (char *)malloc(sizeof(char) * (x_len + 1));
		if (!tab[y])
			return (free_it(tab));
		x = 0;
		while (*s != c && *s)
		{
			tab[y][x] = *s;
			x++;
			s++;
		}
		tab[y][x] = '\0';
		y++;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	y_len;
	char	**tab;

	if (!s)
		return (NULL);
	y_len = y_tab(s, c);
	tab = (char **)malloc(sizeof(char *) * (y_len + 1));
	if (!tab)
		return (NULL);
	tab[y_len] = 0;
	if (!(split_it(tab, s, y_len, c)))
		return (NULL);
	return (tab);
}
