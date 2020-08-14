/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahallain <ahallain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:56:27 by ahallain          #+#    #+#             */
/*   Updated: 2019/11/26 17:49:02 by ahallain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "color.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		readline(int fd, size_t count, char *name)
{
	int		ret;
	char	*line;

	ret = get_next_line(fd, &line);
	reset();
	printf("resulte: ");
	boldcyan();
	printf("%d", ret);
	reset();
	printf(", line %zu in %s: ", count, name);
	boldblue();
	printf("%s", line);
	reset();
	if(ret + 1)
		free(line);
	printf("$\n");
	return (ret);
}

void	readfile(char *name)
{
	int		fd;
	int		ret;
	int		repeat;
	size_t	count;

	fd = open(name, O_RDONLY);
	repeat = 0;
	count = 0;
	ret = 1;
	while (ret > 0 || repeat--)
		ret = readline(fd, ++count, name);
	ret = readline(fd, ++count, name);
	close(fd);
}

void	readfile_bonus(char *name1, char *name2)
{
	int		fd1;
	int		fd2;
	int		ret1;
	int		ret2;
	size_t	count1;
	size_t	count2;

	fd1 = open(name1, O_RDONLY);
	fd2 = open(name2, O_RDONLY);
	count1 = 0;
	count2 = 0;
	ret1 = 1;
	ret2 = 1;
	while (ret1 || ret2)
	{
		if (ret1 > 0)
			ret1 = readline(fd1, ++count1, name1);
		if (ret2 > 0)
			ret2 = readline(fd2, ++count2, name2);
	}
	readline(fd1, ++count1, name1);
	readline(fd2, ++count2, name2);
	close(fd1);
	close(fd2);
}

int		main(int argc, char **argv)
{
	int	index1;
	int	index2;
	
	if (argc == 1)
		return (0);
	if (argc == 2)
		readfile(argv[1]);
	else {
		index1 = 0;
		while (++index1 < argc - 1)
		{
			index2 = 0;
			while (++index2 < argc)
				if (index1 != index2)
					readfile_bonus(argv[index1], argv[index2]);
		}
	}
	if (argc > 2 && atoi(argv[2]))
		getchar();
	return (1);
}
