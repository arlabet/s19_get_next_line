/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:57:40 by nsahloum          #+#    #+#             */
/*   Updated: 2020/01/29 16:51:41 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	n_indice(char *charac)
{
	size_t i;

	i = 0;
	while (n_in_string(charac[i]))
		i++;
	return (i);
}

int	read_charac(int fd)
{
	char *charac;

	if (!(charac = malloc(sizeof(char) * 2)))
		return (0);
	read(fd, charac, 1);
	printf("%s", charac);
	return (1);
}

int	main(void)
{
	int		fd;

	fd = open("numbers.dict", O_RDONLY);
	read_charac(fd);
}
