/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypark <ypark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 19:58:42 by ypark             #+#    #+#             */
/*   Updated: 2021/01/11 01:20:06 by ypark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE	10
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

int		get_next_line(int fd, char **line);

size_t		ft_strlcpy(char *restrict dst,
						const char *restrict src, size_t dstsize);
char	*ft_strjoin(char const *s1, char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strndup(const char *s1, size_t size);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);

#endif
