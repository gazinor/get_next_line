/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:52:47 by glaurent          #+#    #+#             */
/*   Updated: 2019/10/29 14:32:32 by glaurent         ###   ########.fr       */
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
	int		fd;
	int		fd2;
	int		fd3;
	int		ret;
	int		ret2;
	int		ret3;

	fd = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	fd3 = open(av[3], O_RDONLY);
	(void)ac;
	ret = 1;
	ret2 = 1;
	ret3 = 1;
	while (ret > 0 || ret2 > 0 || ret3 > 0)
	{
		ret = get_next_line(fd, &line);
		printf("ret  %d : %s\n", ret, line);
		if (ret != -1)
			free(line);
		ret2 = get_next_line(fd2, &line);
		printf("ret2 %d : %s\n", ret2, line);
		if (ret2 != -1)
			free(line);
		ret3 = get_next_line(fd3, &line);
		printf("ret3 %d : %s\n", ret3, line);
		if (ret3 != -1)
			free(line);
	}
	system("leaks a.out");
	close(fd);
	return (0);
}
