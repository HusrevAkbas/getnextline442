/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:08:21 by huakbas           #+#    #+#             */
/*   Updated: 2024/10/31 16:25:36 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
/*
	Return value:

	1- Read line: correct behavior
	2- NULL: there is nothing else to read, or an error occurred
*/
char	*clear(char **total)
{
	int	i;

	i = 0;
	while (i < 1024)
	{
		if (total[i])
		{
			free(total[i]);
			total[i] = NULL;
		}
		i++;
	}
	return (NULL);
}

char	*get_nl(char **total, int fd)
{
	char	*newline;
	char	*result;

	newline = ft_strchr(total[fd], '\n');
	result = malloc((newline - total[fd] + 2) * sizeof(char));
	if (!result)
		return (clear(total));
	result[newline - total[fd] + 1] = 0;
	ft_memmove(result, total[fd], newline - total[fd] + 1);
	ft_memmove(total[fd], newline + 1, ft_strlen(newline));
	return (result);
}

char	*read_file(char **total, char *buffer, int fd, int *bytes)
{
	char	*middle;

	while (total[fd] && !ft_strchr(total[fd], '\n') && *bytes > 0)
	{
		*bytes = read(fd, buffer, BUFFER_SIZE);
		if (*bytes == -1)
			return (free(total[fd]), total[fd] = NULL, NULL);
		if (*bytes > 0)
		{
			buffer[*bytes] = 0;
			middle = total[fd];
			total[fd] = ft_strnjoin(total[fd], buffer, *bytes);
			free(middle);
			if (!total[fd])
				return (clear(total));
		}
		else if (*bytes == 0)
			return (total[fd]);
		else
			return (clear(total));
	}
	return (total[fd]);
}

char	*set_line(char **total, char *buffer, int fd)
{
	char	*result;
	int		bytes;

	bytes = 1;
	total[fd] = read_file(total, buffer, fd, &bytes);
	if (!total[fd])
		return (clear(total));
	if (bytes == 0 && !total[fd][0])
		return (free(total[fd]), total[fd] = NULL, NULL);
	else if (total[fd] && !ft_strchr(total[fd], '\n'))
	{
		result = malloc((ft_strlen(total[fd]) + 1) * sizeof(char));
		if (!result)
			return (clear(total));
		result[ft_strlen(total[fd])] = 0;
		ft_memmove(result, total[fd], ft_strlen(total[fd]));
		total[fd][0] = 0;
		return (result);
	}
	else if (total[fd] && ft_strchr(total[fd], '\n'))
		return (get_nl(total, fd));
	else
		return ("something");
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*total[1024];
	char		*result;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (clear(total));
	if (!total[fd])
	{
		total[fd] = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!total[fd])
			return (clear(total));
		total[fd][0] = 0;
	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (clear(total));
	if (ft_strchr(total[fd], '\n'))
		result = get_nl(total, fd);
	else
		result = set_line(total, buffer, fd);
	free(buffer);
	return (result);
}
