/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:26:19 by glaurent          #+#    #+#             */
/*   Updated: 2019/10/24 15:51:52 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
t_list		*ft_create_fd(int fd, t_list **list)
{
	while (*list)
		list = &(*list)->next;
	if (!(*list = malloc(sizeof(t_list))))
		return (NULL);
	(*list)->fd = fd;
	(*list)->buffer = NULL;
	(*list)->next = NULL;
	return (*list);
}

t_list		*ft_find_fd(int fd, t_list **list)
{
	while (*list)
	{
		if ((*list)->fd == fd)
			return (*list);
		list = &(*list)->next;
	}
	return(ft_create_fd(fd, list));
}

int			ft_check(int fd, char **buffer, char **line)
{
	if (fd == -1 || !line)
		return (-1);
	if (!*buffer)
	{
		if (!(*buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
		*buffer[0] = '\0';
	}
	return (0);
}

char		*ft_read_n_check(int fd, char *buffer)
{
	int		ret;
	char	tmp[BUFFER_SIZE + 1];
	int		i;
	char	*tarace;

	while ((ret = read(fd, tmp, BUFFER_SIZE)) > 0)
	{
		i = 0;
		tmp[ret] = '\0';
		while (tmp[i] && tmp[i] != '\n')
			++i;
		if (tmp[i] == '\n')
		{
			tarace = ft_strjoin(buffer, tmp);
			free(buffer);
			buffer = tarace;
			free(tarace);
			return (buffer);
		}
		tarace = ft_strjoin(buffer, tmp);
		free(buffer);
		buffer = tarace;
		free(tarace);
	}
	return (buffer);
}

int			get_next_line(int fd, char **line)
{
	static t_list	*list = NULL;
	t_list			*copy;
	int				i;

	i = 0;
	if (!(copy = &*ft_find_fd(fd, &list)) ||
			ft_check(fd, &copy->buffer, line) == -1)
	{
		*line = ft_strdup("");
		return (-1);
	}
	copy->buffer = ft_read_n_check(fd, copy->buffer);
	if (copy->buffer[i])
	{
		while (copy->buffer[i] && copy->buffer[i] != '\n')
			++i;
		*line = ft_substr(copy->buffer, 0, i);
		copy->buffer = &(copy->buffer[i + 1]);
		return (1);
	}
	else
		*line = ft_strdup("");
	return (0);
}
