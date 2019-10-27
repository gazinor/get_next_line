/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:52:47 by glaurent          #+#    #+#             */
/*   Updated: 2019/10/27 18:21:22 by glaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int         get_next_line(int fd, char **line);

int		main(int ac, char **av)
{
	char	*line;
	int		ret;
	int		ret2;
	int		ret3;
	int		fd;
	int		fd2;
	int		fd3;

	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	fd3 = open(av[3], O_RDONLY);
	(void)ac;
	ret = get_next_line(fd, &line);
	printf("ret : %d | fd  : %s\n", ret, line);
	free(line);
	ret2 = get_next_line(fd2, &line);
	printf("ret : %d | fd2 : %s\n", ret2, line);
	free(line);
	ret3 = get_next_line(fd3, &line);
	printf("ret : %d | fd3 : %s\n", ret3, line);
	free(line);
	while (ret > 0 || ret2 > 0 || ret3 > 0)
	{
		ret = get_next_line(fd, &line);
	printf("ret : %d | fd  : %s\n", ret, line);
		free(line);
		ret2 = get_next_line(fd2, &line);
	printf("ret : %d | fd2 : %s\n", ret2, line);
		free(line);
		ret3 = get_next_line(fd3, &line);
	printf("ret : %d | fd3 : %s\n", ret3, line);
		free(line);
	}
	close(fd);
	close(fd2);
	close(fd3);
	return (0);
}
