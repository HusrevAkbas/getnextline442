/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:08:21 by huakbas           #+#    #+#             */
/*   Updated: 2024/10/21 14:28:43 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
	Return value:

	1- Read line: correct behavior
	2- NULL: there is nothing else to read, or an error occurred
*/
size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
	{
		length++;
	}
	return (length);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*pointer;
	unsigned int	s1_length;
	unsigned int	s2_length;
	unsigned int	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_length = strlen(s1);
	s2_length = strlen(s2);
	pointer = malloc(s1_length + s2_length + 1);
	if (pointer == NULL)
		return (NULL);
	i = 0;
	while (*s1)
		pointer[i++] = *s1++;
	while (*s2)
		pointer[i++] = *s2++;
	pointer[i] = 0;
	return (pointer);
}

int	read_bytes(int fd, char *buffer)
{
	char	onechar[2];
	int		i;

	i = 0;
	onechar[1] = 0;	
	while ((i += read(fd, onechar, 1)))
	{
		if (onechar[0] == '\n' || i == BUFFER_SIZE - 2)
		{
			buffer[i - 1] = onechar[0];
			buffer[i] = 0;
			return (i);
		}
		buffer[i - 1] = onechar[0];
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*line;
	char	*middle_str;
	int		bytes;

	line = malloc(BUFFER_SIZE);
	line[BUFFER_SIZE-1] = 0;
	bytes = read_bytes(fd, buffer);
	if (bytes)
		line = ft_memmove(line, buffer, bytes);
	//while (line[ft_strlen(line) - 1] != '\n' && bytes)
	//{
	//	bytes = read_bytes(fd, buffer);
	//	middle_str = line;
	//	line = ft_strjoin(middle_str, buffer);
	//	free(middle_str);
	//}
	line[ft_strlen(line)]= 0;
	return (line);
}
