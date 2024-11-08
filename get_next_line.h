/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 00:10:43 by razaccar          #+#    #+#             */
/*   Updated: 2024/02/02 03:52:51 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strndup(char *str, size_t start, size_t end);
char	*ft_strjoin(char *s1, char *s2);

#endif