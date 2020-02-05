/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:57:40 by nsahloum          #+#    #+#             */
/*   Updated: 2020/02/04 20:57:15 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;
	if (!src)
		return (NULL);
	if (!(dest = malloc((sizeof(char) * ft_strlen(src)) + 1)))
	{
		free(dest);
		return (NULL);
	}
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*read_file(char *str, int fd)
{
	char	*buff;
	int		ret;
	int		i;

	i = 0;
	if (str == NULL)
		str = ft_strdup("");
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (NULL);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		str = ft_strjoin(str, buff);
		while (str[i])
		{
			if (str[i] == '\n')
				return (str);
			i++;
		}
	}
	free(buff);
	return (str);
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	int			i;

	i = 0;
	if (BUFFER_SIZE <= 0 || !fd)
		return (-1);
	str = read_file(str, fd);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		*line = ft_substr(str, 0, i);
		str = &str[i + 1];
		return (1);
	}
	else if (str[i] == '\0')
	{
		*line = ft_substr(str, 0, i);
		str = &str[i];
		return (0);
	}
	return(-1);
}
