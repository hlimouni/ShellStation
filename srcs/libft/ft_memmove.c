/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:20:58 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/14 15:30:54 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s1;
	char	*s2;
	size_t	i;

	if (dst == 0 && src == 0)
		return (0);
	s1 = (char *)dst;
	s2 = (char *)src;
	i = -1;
	if (len)
	{
		if (s1 > s2)
		{
			len--;
			while (++i <= len)
				s1[len - i] = s2[len - i];
		}
		else
			while (len--)
				*s1++ = *s2++;
	}
	return (dst);
}
