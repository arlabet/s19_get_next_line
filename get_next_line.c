/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:57:40 by nsahloum          #+#    #+#             */
/*   Updated: 2020/01/29 18:22:38 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	size_one_line(int fd)
{
	size_t	index_n;
	char	*one_line;

	index_n = 0;
	if (!(one_line = malloc(sizeof(char) * 2)))
		return (0);
	while (one_line[0] != '\n')
	{
		read(fd, one_line, 1);
		index_n++;
	}
	return (index_n);
}

char	*cpy_one_line(int fd)
{
	size_t index_n;

	index_n = size_one_line(fd);
}

int		main(void)
{
	int		fd;

	fd = open("numbers.dict", O_RDONLY);
	size_one_line(fd);
	size_one_line(fd);
	size_one_line(fd);
	return (0);
}
