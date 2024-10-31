/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:08:21 by huakbas           #+#    #+#             */
/*   Updated: 2024/10/31 16:16:25 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
	Return value:

	1- Read line: correct behavior
	2- NULL: there is nothing else to read, or an error occurred
*/
char	*clear(char **total)
{
	free(*total);
	*total = NULL;
	return (NULL);
}

char	*get_nl(char **total)
{
	char	*newline;
	char	*result;

	newline = ft_strchr(*total, '\n');
	result = malloc((newline - *total + 2) * sizeof(char));
	if (!result)
		return (clear(total));
	result[newline - *total + 1] = 0;
	ft_memmove(result, *total, newline - *total + 1);
	ft_memmove(*total, newline + 1, ft_strlen(newline));
	return (result);
}

char	*read_file(char *total, char *buffer, int fd, int *bytes)
{
	char	*middle;

	while (total && !ft_strchr(total, '\n') && *bytes > 0)
	{
		*bytes = read(fd, buffer, BUFFER_SIZE);
		if (*bytes == -1)
			return (clear(&total));
		if (*bytes > 0)
		{
			buffer[*bytes] = 0;
			middle = total;
			total = ft_strnjoin(total, buffer, *bytes);
			if (!total)
			{
				free(middle);
				return (clear(&total));
			}
			free(middle);
		}
		else if (*bytes == 0)
			return (total);
		else
			return (clear(&total));
	}
	return (total);
}

char	*getline(char **total, char *buffer, int fd)
{
	char	*result;
	int		bytes;

	bytes = 1;
	*total = read_file(*total, buffer, fd, &bytes);
	if (!*total)
		return (NULL);
	if (bytes == 0 && !(**total))
		return (NULL);
	else if (**total && !ft_strchr(*total, '\n'))
	{
		result = malloc((ft_strlen(*total) + 1) * sizeof(char));
		if (!result)
			return (clear(total));
		result[ft_strlen(*total)] = 0;
		ft_memmove(result, *total, ft_strlen(*total));
		**total = 0;
		return (result);
	}
	else if (**total && ft_strchr(*total, '\n'))
		return (get_nl(total));
	else
		return ("something");
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*total;
	char		*result;

	if (fd == -1 || BUFFER_SIZE < 1)
		return (clear(&total));
	if (!total)
	{
		total = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!total)
			return (NULL);
		total[0] = 0;
	}
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (clear(&total));
	if (ft_strchr(total, '\n'))
		result = get_nl(&total);
	else
		result = getline(&total, buffer, fd);
	free(buffer);
	return (result);
}
