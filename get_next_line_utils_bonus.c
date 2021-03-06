/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzaccari <rzaccari@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:27:47 by rzaccari          #+#    #+#             */
/*   Updated: 2022/02/07 20:40:00 by rzaccari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	cmp;

	if (!str)
		return (0);
	cmp = 0;
	while (str[cmp])
		cmp++;
	return (cmp);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*string;
	int		stringlen;
	int		i;
	int		j;

	stringlen = ft_strlen(str1) + ft_strlen(str2) + 1;
	string = malloc(stringlen * sizeof(char));
	if (string == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (str1)
		while (str1[j] != '\0')
			string[i++] = str1[j++];
	j = 0;
	if (str2)
		while (str2[j] != '\0')
			string[i++] = str2[j++];
	string[i] = 0;
	free(str1);
	return (string);
}

char	*ft_strndup(char *str, int start, int end)
{
	char	*copy;
	int		i;

	i = 0;
	if (end < start || start < 0 || ft_strlen(str) <= start)
		return (NULL);
	if (end > ft_strlen(str))
		end = ft_strlen(str) - 1;
	copy = (char *)malloc((end - start + 2) * sizeof(char));
	if (!copy)
		return (NULL);
	while (start <= end)
		copy[i++] = str[start++];
	copy[i] = '\0';
	return (copy);
}
