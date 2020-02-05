/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leak_detector.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsahloum <nsahloum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:28:48 by maperrea          #+#    #+#             */
/*   Updated: 2020/02/05 19:31:44 by nsahloum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEAK_DETECTOR_H
# define LEAK_DETECTOR_H

# ifndef CHECK_LEAKS

#  include <unistd.h>
#  include <string.h>
#  include <stdio.h>
#  include <stdlib.h>

void	*malloc_leak(size_t size, const char *file, int line);
void	free_leak(void *ptr);
void	print_leaks();

#  define malloc(X) malloc_leak(X, __FILE__, __LINE__)
#  define free(X)  free_leak(X)
#  define CHECK print_leaks();

# else
#  define CHECK
# endif

#endif
