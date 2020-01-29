/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:57:40 by nsahloum          #+#    #+#             */
/*   Updated: 2020/01/29 17:19:19 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		n_in_string(char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (0);
	}
	return (1);
}

char	*read_charac(int fd)
{
	char *charac;

	if (!(charac = malloc(sizeof(char) * 2)))
		return (NULL);
	read(fd, charac, 1);
	printf("%s", charac);
	return (charac);
}

int		get_next_line(int fd, char **line)
{
	char	*charac;
	size_t	i;

	charac = read_charac(fd);
	if (!(*line = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	i = 0;
	if (n_in_string(charac))
	{
		while (charac[i])
		{
			
		}
	}
	printf("%s", *line);
	return (1);
}

int		main(void)
{
	int		fd;

	fd = open("numbers.dict", O_RDONLY);
	read_charac(fd);
}
