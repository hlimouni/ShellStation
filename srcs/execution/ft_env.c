/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 18:06:51 by hlimouni          #+#    #+#             */
/*   Updated: 2021/12/23 19:57:20 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	ft_env(void)
{
	int		i;

	i = 0;
	while (i < g_vars.env_table.name.used_size)
	{
		if (g_vars.env_table.value.elements[i])
			printf("%s=%s\n", g_vars.env_table.name.elements[i],
				g_vars.env_table.value.elements[i]);
		i++;
	}
}
