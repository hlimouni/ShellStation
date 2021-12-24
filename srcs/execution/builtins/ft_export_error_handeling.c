/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_error_handeling.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlimouni <hlimouni@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 09:48:24 by hlimouni          #+#    #+#             */
/*   Updated: 2021/12/24 12:12:16 by hlimouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execution.h"

static int	invalid_option_error(char *arg)
{
	ft_putstr_fd("minishell: export: ", 2);
	write(2, arg, 2);
	ft_putstr_fd(": invalid option\n", 2);
	ft_putstr_fd("export: usage: export [-nf]", 2);
	ft_putstr_fd("[name[=value] ...] or export -p\n", 2);
	g_vars.last_err_num = 2;
	return (0);
}

static int	invalid_identifier_error(char *arg)
{
	ft_putstr_fd("minishell: export: '", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	g_vars.last_err_num = 1;
	return (0);
}

int	is_arg_valid(char *arg)
{
	int	i;
	int	namelen;

	if (*arg == '-')
		return (invalid_option_error(arg));
	if (ft_isdigit(*arg))
		return (invalid_identifier_error(arg));
	i = 0;
	while (arg[i] && ft_strncmp(&arg[i], "+=", 2)
		&& arg[i] != '=')
		i++;
	namelen = i;
	i = 0;
	while (i < namelen && (ft_isalnum(arg[i]) || arg[i] == '_'))
		i++;
	if (i < namelen)
		return (invalid_identifier_error(arg));
	return (namelen);
}
