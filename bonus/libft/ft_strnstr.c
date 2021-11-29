/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:10:36 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/14 16:12:41 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;

	if (!*needle)
		return ((char *)haystack);
	if (len)
	{
		while (*haystack && len--)
		{
			i = 0;
			n = len;
			if (haystack[i] == needle[i])
			{
				i++;
				while (haystack[i] == needle[i] && needle[i] && haystack[i]
					&& n--)
					i++;
				if (!needle[i])
					return ((char *)haystack);
			}
			haystack++;
		}
	}
	return (NULL);
}
