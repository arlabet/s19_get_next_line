/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:57:40 by nsahloum          #+#    #+#             */
/*   Updated: 2020/02/03 21:16:37 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd)
{
	char	*buff;
	int		rt;

	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (0);
	rt = read(fd, buff, BUFFER_SIZE);
	buff[rt] = '\0';
	return (buff);
}

int		ft_check_n(int fd)
{
	char	*str;
	char	*rest;
	char 	*line;
	int		i;
	int 	j;

	i = 0;
	str = ft_read_file(fd);
	while (str[i] != '\n')

		i++;
	if (str[i] == '\n')
	{
		if(!(rest = malloc(sizeof(char) * (BUFFER_SIZE - i + 1))))
			return (0);
		j = 0;
		while(str[i])
			str[j + i] = rest[j];
			j++;
	}
	else if (str[i] == '\0')
		if (i < BUFFER_SIZE)
}

int	main(void)
{
	int		fd;
	char *str;
	str = "";
	fd = open("poeme.txt", O_RDONLY);
	ft_check_n(fd, str);
	return (0);
}
