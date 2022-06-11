/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:27:55 by rzaccari          #+#    #+#             */
/*   Updated: 2022/06/11 17:37:55 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*string = NULL;
	char		buffer[BUFFER_SIZE + 1];
	int			read_bytes;

	if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0)
		return (NULL);
	if (string && has_line(string) == 1)
		return (get_line(&string));
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	if (read_bytes < 0)
	{
		free(string);
		return (NULL);
	}
	buffer[read_bytes] = '\0';
	while (read_bytes > 0)
	{
		string = ft_strjoin(string, buffer);
		if (has_line(string) == 1)
			break ;
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		buffer[read_bytes] = '\0';
	}
	return (get_line(&string));
}

char	*get_line(char **str)
{
	char	*line;
	char	*temp;
	int		i;

	i = 0;
	if (str == NULL || *str == NULL)
	{
		free(*str);
		return (NULL);
	}
	while ((*str)[i] != '\0' && (*str)[i] != '\n')
		i++;
	line = ft_strndup(*str, 0, i);
	if (has_line(*str) == 0)
		temp = NULL;
	else
		temp = ft_strndup(*str, i + 1, ft_strlen(*str));
	free(*str);
	*str = temp;
	return (line);
}

int	has_line(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
