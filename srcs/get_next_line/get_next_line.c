/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltafah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 03:44:32 by iltafah           #+#    #+#             */
/*   Updated: 2021/06/12 07:56:00 by iltafah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_n(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

int	fill_line(int fd, char **line, char **content)
{
	char	*tmp;
	int		end;

	end = 0;
	while (content[fd][end] != '\n' && content[fd][end] != '\0')
		end++;
	if (content[fd][end] == '\n')
	{
		*line = ft_substr(content[fd], 0, end);
		tmp = ft_strdup(content[fd] + end + 1);
		free(content[fd]);
		content[fd] = tmp;
	}
	else if (content[fd][end] == '\0')
	{
		*line = ft_strdup(content[fd]);
		free(content[fd]);
		content[fd] = NULL;
		return (0);
	}
	return (1);
}

int	check_error(int size, int fd, char **line)
{
	char	buffer;

	if (fd < 0 || fd > 4864 || size <= 0 || !line)
		return (ERROR);
	if (read(fd, &buffer, 0) < 0)
		return (ERROR);
	return (1);
}

void	read_input(int fd, char *buffer, char **content)
{
	int			r;
	char		*tmp;

	r = read(fd, buffer, BUFFER_SIZE);
	while (r > 0)
	{
		buffer[r] = '\0';
		tmp = ft_strjoin(content[fd], buffer);
		free(content[fd]);
		content[fd] = tmp;
		if (is_n(buffer))
			break ;
		r = read(fd, buffer, BUFFER_SIZE);
	}
}

int	get_next_line(int fd, char **line)
{
	static char	*content[4864];
	char		*buffer;
	int			e;

	e = check_error(BUFFER_SIZE, fd, line);
	if (e == ERROR)
		return (ERROR);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ERROR);
	if (!content[fd])
		content[fd] = ft_strdup("");
	if (!is_n(content[fd]))
		read_input(fd, buffer, content);
	free(buffer);
	return (fill_line(fd, line, content));
}
