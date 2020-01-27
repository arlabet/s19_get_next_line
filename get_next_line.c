/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 19:57:40 by nsahloum          #+#    #+#             */
/*   Updated: 2020/01/27 16:10:37 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int get_next_line(int fd)
{
	char *str;
	
	if (!(str = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (0);
	read(fd, str, BUFFER_SIZE);
	//printf("%s", str);
	return (1);
}

int main(void)
{
	int fd;
	fd = open("numbers.dict", O_RDONLY);
	get_next_line(fd);
}