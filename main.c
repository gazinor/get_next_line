/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glaurent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 20:52:47 by glaurent          #+#    #+#             */
/*   Updated: 2019/11/04 14:27:48 by glaurent         ###   ########.fr       */
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
	int		ret;

	fd = open(av[1], O_RDONLY);
	(void)ac;
	(void)av;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("ret %d : %s\n", ret, line);
		free(line);
	}
	printf("ret %d : %s\n", ret, line);
	free(line);
	system("leaks a.out");
	close(fd);
	return (0);
}
