/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 17:15:14 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/14 15:51:16 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*r;
	int		len;

	r = (char *)s;
	len = ft_strlen(s) + 1;
	while (len--)
	{
		if (r[len] == (char)c)
			return (r + len);
	}
	return (NULL);
}
