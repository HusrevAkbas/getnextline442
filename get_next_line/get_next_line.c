/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:08:21 by huakbas           #+#    #+#             */
/*   Updated: 2024/10/23 16:23:55 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
	Return value:

	1- Read line: correct behavior
	2- NULL: there is nothing else to read, or an error occurred
*/
	//check buffer length
	//check buffer has new line
	//read file
	//check read return !0
	//check buffer length 
	//check buffer has new line

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*result;
	char		*middle;
	char		*newline;
	int			bytes;

	result = malloc(1);
	bytes = 1;
	if (fd == - 1)
		return (NULL);
	if (!(*buffer))
		bytes = read(fd, buffer, BUFFER_SIZE);
	if (!(*buffer) && bytes == 0)
		return (NULL);
	while (*buffer && !ft_strchr(buffer, '\n') && !bytes)
	{
		middle = result;
		result = ft_strnjoin(result, buffer, BUFFER_SIZE - 1);
		bytes = read(fd, buffer, BUFFER_SIZE - 1);
		free(middle);
	}
	if (*buffer && (newline = ft_strchr(buffer, '\n')))
	{
		middle = result;
		result = ft_strnjoin(result, buffer, newline - buffer +1);
		free(middle);
		return (result);
	}
	return (result);
}
