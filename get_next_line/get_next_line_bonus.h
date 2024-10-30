/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:10:35 by huakbas           #+#    #+#             */
/*   Updated: 2024/10/30 15:40:39 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdio.h> //	DELETE THIS LINE
# include <stdlib.h>
# include <unistd.h>
# include <aio.h>
# include <string.h> // DELETE THIS LINE
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif //BUFFER_SIZE

typedef struct s_list
{
	int				file;
	char			*line;
	struct s_list	*next;
}	t_list;

char	*get_next_line(int fd);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strnjoin(char *dst, char *src, size_t size);

#endif // GET_NEXT_LINE_BONUS_H