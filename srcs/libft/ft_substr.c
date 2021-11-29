/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:30:43 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/16 15:07:31 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*sub_str;

	if (!s)
		return (NULL);
	sub_str = NULL;
	size = ft_strlen(s);
	if (start < size)
	{
		sub_str = (char *)malloc(sizeof(char) * (len + 1));
		if (!sub_str)
			return (NULL);
		i = 0;
		while (i < len)
			sub_str[i++] = s[start++];
		sub_str[i] = '\0';
	}
	else
		sub_str = ft_strdup("\0");
	return (sub_str);
}
