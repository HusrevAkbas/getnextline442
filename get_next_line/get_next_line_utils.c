/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:24:03 by huakbas           #+#    #+#             */
/*   Updated: 2024/10/21 19:36:00 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strchr(const char *s, int c)
{
	char	*pointer;
	int		size;
	int		i;

	while (c >= 128)
		c = c - 128;
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