/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:08:21 by huakbas           #+#    #+#             */
/*   Updated: 2024/10/17 15:07:50 by huakbas          ###   ########.fr       */
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
	int			i;
	
	i = 0;
	while (read(fd, strofonechar, 1))
	{
		if (!strofonechar[0])
			return ;
		buffer[i] = strofonechar[0];
		if (strofonechar[0] == '\n')
			return ;
		i++;
	}
}

char	*get_next_line(int fd)
{
	printf("in func %d\n", BUFFER_SIZE);
	static char	*buffer;
	//char		*strofonechar;
	//int			i;
	//i = 0;
	buffer = malloc(BUFFER_SIZE);
	read_bytes(fd, buffer);
	//while (read(fd, strofonechar, 1))
	//{
	//	if (!strofonechar[0])
	//		return ;
	//	buffer[i] = strofonechar[0];
	//	if (strofonechar[0] == '\n')
	//		return ;
	//}
	
	read(fd, buffer, BUFFER_SIZE);
	printf("%s\n", buffer);
	free(buffer);
	return (0);
}