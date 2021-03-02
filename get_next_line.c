/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypark <ypark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 19:35:58 by ypark             #+#    #+#             */
/*   Updated: 2021/01/11 01:40:53 by ypark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char		*tmp;
	const unsigned char	*s;

	if (dst == 0 && src == 0)
		return (0);
	tmp = dst;
	s = src;
	while (n--)
		*tmp++ = *s++;
	return (dst);
}

int		check_enter(char **fd_buf, char **line)
{
	int		i;
	char	*file_buf;

	i = 0;
	file_buf = *fd_buf;
	while(file_buf[i])
	{
		if (file_buf[i] == '\n')
			break ;
		i++;
	}
	if (file_buf[i] == '\n')
	{
		*line = ft_strndup(file_buf, i);
		*fd_buf = ft_strdup(file_buf + i + 1);
		free(file_buf);
		return (1);
	}
	return (0);
}

int		ret_value(int ret, char *fd_buf_arr,char **line)
{
	if (ret == 0)
		return (0);
	else if (ret > 0)
		return (1);
	else
	{
		*line = ft_strdup(fd_buf_arr);
		free(fd_buf_arr);
		return (-1);
	}
}

int		get_next_line(int fd, char **line)
{
	static	char	*fd_buf[OPEN_MAX];
	char			*buf;
	int				ret;
	char			*free_buf_addr;

	buf = (char *)malloc(BUFFER_SIZE * sizeof(char));
	while ((ret = read(fd, buf ,BUFFER_SIZE)) >= 0) // 정상 작동
	{
		free_buf_addr = fd_buf[fd];
		if (fd_buf[fd])
			fd_buf[fd] = ft_strjoin(fd_buf[fd], buf);
		else
			fd_buf[fd] = ft_strdup(buf);
		if (!free_buf_addr)
			free(free_buf_addr);
		if (check_enter(&fd_buf[fd], line))
			break;
	}
	return ret_value(ret, fd_buf[fd], line);
	return (0);
}
