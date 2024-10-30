/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:24:03 by huakbas           #+#    #+#             */
/*   Updated: 2024/10/30 11:35:59 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

size_t	ft_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

char	*ft_strnjoin(char *str1, char *str2, size_t size)
{
	char	*new;
	size_t	i;
	size_t	j;
	size_t	dst_length;

	if (!str1)
		return (NULL);
	dst_length = ft_strlen(str1);
	i = 0;
	new = malloc(size + dst_length + 1);
	if (new)
	{
		while (str1[i])
		{
			new[i] = str1[i];
			i++;
		}
		j = 0;
		while (str2[j] && j < size)
			new[i++] = str2[j++];
		new[i] = 0;
	}
	return (new);
}

char	*ft_strchr(char *s, int c)
{
	char	*pointer;
	int		size;
	int		i;

	i = 0;
	size = ft_strlen(s);
	pointer = (char *) s;
	while (i <= size)
	{
		if (pointer[i] == c)
			return (&pointer[i]);
		i++;
	}
	return (0);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;

	destination = (unsigned char *) dest;
	source = (unsigned char *) src;
	if (dest == src)
		return (dest);
	if (dest - src < 0)
	{
		while (n > 0)
		{
			*destination++ = *source++;
			n--;
		}
	}
	else
	{
		while (n > 0)
		{
			n--;
			destination[n] = source[n];
		}
	}
	return (dest);
}
