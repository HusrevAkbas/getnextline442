/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: husrevakbas <husrevakbas@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:08:21 by huakbas           #+#    #+#             */
/*   Updated: 2024/10/23 22:58:15 by husrevakbas      ###   ########.fr       */
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
char	*read_fd(char **total, char *buffer, int fd)
{
	int		bytes;
	char	*result;
	char	*middle;
	char	*newline;

	bytes = 1;
	while (bytes > 0 && !ft_strchr(*total, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
			return (NULL); //free total return Null
		if (bytes == 0)
			break;
		middle = *total;
		*total = ft_strnjoin(middle, buffer, bytes);
		free(middle);
	}
	if (bytes == 0 && !**total)
		return (NULL); //free total
	if (**total && (newline = ft_strchr(*total, '\n')))
	{
		result = ft_calloc(newline - *total + 2, sizeof(char));
		ft_memmove(result, *total, newline - *total + 1);
		result[newline - *total + 1]=0;
		ft_memmove(*total, newline + 1, ft_strlen(newline) - 1);
		return (result);
	}
	if (**total && !ft_strchr(*total, '\n'))
	{
		result = ft_calloc(ft_strlen(*total) + 1, sizeof(char));
		ft_memmove(result, *total, ft_strlen(*total) + 1);
		*total[0] = 0;
		return (result);
	}
	else 
		return ("something");
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*total;
	char		*result;
	char		*newline;

// printf("----%s\n", total);
	if (fd == - 1)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);//free everything than return null
	if (!total)
		total = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (*total && (newline = ft_strchr(total, '\n')))
	{
		result = ft_calloc(newline - total + 2, sizeof(char));
		ft_memmove(result, total, newline - total + 1);
		result[newline - total + 1]=0;
		ft_memmove(total, newline + 1, ft_strlen(newline));
		return (result);
	}
	result = read_fd(&total, buffer, fd);
	free(buffer);
	return (result);
}
