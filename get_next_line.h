/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 20:04:33 by nsahloum          #+#    #+#             */
/*   Updated: 2020/01/29 14:40:00 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include "get_next_line.h"
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strcat(char *dest, char *src);
char			*ft_strjoin(char *s1, char *s2);


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

#endif
