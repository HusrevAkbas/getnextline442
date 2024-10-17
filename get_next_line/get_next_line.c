/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:08:21 by huakbas           #+#    #+#             */
/*   Updated: 2024/10/17 16:29:37 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
	Return value:

	1- Read line: correct behavior
	2- NULL: there is nothing else to read, or an error
	occurred
*/
void	read_bytes(int fd, char *buffer)
{
	char		strofonechar[1];
	static int	i;
	
	i = 0;
	while (read(fd, strofonechar, 1))
	{
		if (i == BUFFER_SIZE)
		{
			buffer[BUFFER_SIZE] = 0;
			return ;
		}
		if (!strofonechar[0])
		{
			buffer[BUFFER_SIZE] = 0;
			return ;
		}
		buffer[i] = strofonechar[0];
		if (strofonechar[0] == '\n')
		{
			buffer[BUFFER_SIZE] = 0;
			return ;
		}
		i++;
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	
	buffer = malloc(BUFFER_SIZE + 1);
	
	read_bytes(fd, buffer);
	printf("%s", buffer);
	read_bytes(fd, buffer);
	printf("%s", buffer);
	read_bytes(fd, buffer);
	printf("%s", buffer);
	
	free(buffer);
	return (0);
}