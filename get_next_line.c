/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:57:40 by nsahloum          #+#    #+#             */
/*   Updated: 2020/01/29 17:38:54 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	index_n(int fd)
{
	char	*charac;
	size_t	i;

	i = 0;
	if (!(charac = malloc(sizeof(char) * 2)))
		return (0);
	while (charac[0] != '\n')
	{
		read(fd, charac, 1);
		printf("%c", charac[0]);
		i++;
	}
	printf("%lu", i);
	return (i);
}

int	main(void)
{
	int		fd;

	fd = open("numbers.dict", O_RDONLY);
	index_n(fd);
}
