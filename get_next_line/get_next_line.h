/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huakbas <huakbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 13:10:35 by huakbas           #+#    #+#             */
/*   Updated: 2024/10/21 13:49:23 by huakbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h> //	DELETE THIS LINE
# include <stdlib.h>
# include <unistd.h>
# include <aio.h>
# include <string.h> // DELETE THIS LINE

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1000
#endif //BUFFER_SIZE

char	*get_next_line(int fd);
void	*ft_memmove(void *dest, const void *src, size_t n);

#endif // GET_NEXT_LINE_H