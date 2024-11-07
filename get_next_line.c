/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 00:10:37 by razaccar          #+#    #+#             */
/*   Updated: 2024/09/13 15:00:00 by razaccar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/fcntl.h>
#include <unistd.h>

/**
 * @brief Finds the index of the first occurrence of a newline character
 * in a string.
 *
 * This function searches for the first newline character ('\n') in the given 
 * string and returns its index. If no newline character is found,
 * it returns -1.
 *
 * @param str The string to search for a newline character.
 * @return The index of the first newline character, or -1 if not found.
 */
static int	get_nl_index(char *str)
{
	size_t	pos;

	pos = 0;
	if (!str)
		return (-1);
	while (str[pos])
	{
		if (str[pos] == '\n')
			return (pos);
		pos++;
	}
	return (-1);
}

/**
 * @brief Extracts a line from a string.
 *
 * This function extracts a line from the given string, up to the first 
 * newline character. The extracted line is then removed from the original 
 * string, and the modified string is stored back into the original 
 * string pointer.
 *
 * @param str The string to extract a line from.
 * @return The extracted line, or NULL if the string is empty or NULL.
 */
static char	*get_line(char **str_address)
{
	char	*str;
	char	*line;
	char	*temp;
	int		i;

	str = *str_address;
	if (!(str))
		return (NULL);
	if (get_nl_index(str) < 0)
		temp = NULL;
	else
		temp = ft_strndup(str, get_nl_index(str) + 1, ft_strlen(str) - 1);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	line = ft_strndup(str, 0, i);
	free(str);
	*str_address = temp;
	return (line);
}


/**
 * @brief Reads a file and returns the next line.
 *
 * This function reads the file descriptor and returns the next line 
 * from the file. The function reads the file in chunks of BUFFER_SIZE bytes,
 * and stores the remaining characters in a static string. The next time the 
 * function is called with the same file descriptor, it will continue reading 
 * from the remaining characters in the static string.
 *
 * @param fd The file descriptor to read from.
 * @return The next line from the file, or NULL if an error occurs.
 */
char	*get_next_line(int fd)
{
	static char	*str;
	char		buff[BUFFER_SIZE + 1];
	int			bytes_read;

	if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0)
		return (NULL);
	if (str && get_nl_index(str) >= 0)
		return (get_line(&str));
	bytes_read = read(fd, buff, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		if (str)
			free(str);
		str = NULL;
	}
	while (bytes_read > 0)
	{
		buff[bytes_read] = 0;
		str = ft_strjoin(str, buff);
		if (get_nl_index(str) >= 0)
			break ;
		bytes_read = read(fd, buff, BUFFER_SIZE);
	}
	return (get_line(&str));
}

int	main()
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
/* PSEUDOCODE - exam revision
 *
 *	char *get_next_line(int fd)
 *
 *		static char	*str
 *		char		[BUFFER_SIZE + 1]
 *		int			bytes_read
 *
 *		check fd and BUFFER_SIZE value
 *		check if str && new line in str
 *			true => get_line()
 *		read()
 *		check if bytes_read < 0
 *			true => free(str) and str = NULL
 *		while bytes_read
 *			end buffer with eol
 *			join buffer to str
 *			check if new line in str
 *				true => break()
 *			read()
 *		return get_line()
 *
 *
 *	char *get_line(char *str)
 *	
 *		char	*line
 * 		char	*temp
 *		int		i
 *	
 *		check if str
 *			false => return NULL
 *		chrck if new line in str
 *			true => tmp = strndup(str, nl_index + 1, strlen(str) - 1)
 *			false => tmp = NULL
 *		while i != nl_index
 *			i++
 *		line = strndup(str, 0, i)
 *		free(str)
 *		str = tmp
 *		return line
 */
 
