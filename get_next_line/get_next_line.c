/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:08:21 by huakbas           #+#    #+#             */
/*   Updated: 2024/10/24 13:43:41 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
	Return value:

	1- Read line: correct behavior
	2- NULL: there is nothing else to read, or an error occurred
*/
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
			return (NULL);
		if (bytes)
		{
			middle = *total;
			*total = ft_strnjoin(middle, buffer, bytes);
			free(middle);
		}
	}
	if (bytes == 0 && !(**total))
		return (NULL);
	else if (**total && ft_strchr(*total, '\n'))
	{
		newline = ft_strchr(*total, '\n');
		result = ft_strnjoin("", *total, newline - *total + 1);
		middle = *total;
		*total = ft_strnjoin("", newline + 1, ft_strlen(newline));
		free(middle);
		return (result);
	}
	else if (**total && !ft_strchr(*total, '\n'))
	{
		result = ft_calloc(ft_strlen(*total) + 1, sizeof(char));
		ft_memmove(result, *total, ft_strlen(*total) + 1);
		**total = 0;
		return (result);
	}
	else
		return ("something");
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char	*total;
	char		*result;
	char		*newline;

	if (!fd || fd == -1)
		return (NULL);
	if (!total)
		total = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (*total && ft_strchr(total, '\n'))
	{
		newline = ft_strchr(total, '\n');
		result = ft_strnjoin("", total, newline - total +1);
		ft_memmove(total, newline + 1, ft_strlen(newline));
		return (result);
	}
	result = read_fd(&total, buffer, fd);
	if (!result)
		free(total);
	return (result);
}
