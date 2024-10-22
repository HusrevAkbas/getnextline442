/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:08:21 by huakbas           #+#    #+#             */
/*   Updated: 2024/10/22 20:21:23 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
	Return value:

	1- Read line: correct behavior
	2- NULL: there is nothing else to read, or an error occurred
*/
char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*result;
	char		*middle;
	char		*newline;
	int			bytes;

printf("1:%s\n", buffer);
	result = malloc(1);
	result[0] = 0;
	bytes = 0;
	if (fd == - 1)
		return (NULL);
	if (ft_strlen(buffer) == 0)
		bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes == 0 && strlen(buffer) == 0)
		return (NULL);
	if ((newline = ft_strchr(buffer, '\n')))
	{
		middle = result;
		result = ft_strncat(middle, buffer, newline - buffer + 2);
		ft_memmove(buffer, newline + 1, bytes - (newline - buffer));
printf("|R:%s|B:%s|", result, buffer);
		free(middle);
	}
	//check buffer length
	//check buffer has new line
	//read file
	//check read return !0
	//check buffer length 
	//check buffer has new line
	return (result);
}
