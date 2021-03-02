/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypark <ypark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 18:23:14 by ypark             #+#    #+#             */
/*   Updated: 2021/01/11 01:11:04 by ypark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlcpy(char *restrict dst,
						const char *restrict src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	len;

	if (dst == 0 && src == 0)
		return (0);
	i = 0;
	len = ft_strlen(src);
	while (src[i] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (len);
}

char	*ft_strjoin(char const *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(new = (char *)malloc(sizeof(char) * (len1 + len2 + 1))))
		return (0);
	ft_memcpy(new, s1, len1);
	ft_memcpy(new + len1, s2, len2);
	new[len1 + len2] = 0;
	return (new);
}

char	*ft_strndup(const char *s1, size_t size)
{
	char	*tmp;
	int		len;

	len = ft_strlen(s1);
	len = size > len ? len : size;
	if (!(tmp = malloc(len + 1)))
		return (0);
	ft_memcpy(tmp, s1, len);
	tmp[len] = 0;
	return (tmp);
}

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	int		len;

	len = ft_strlen(s1);
	if (!(tmp = malloc(len + 1)))
		return (0);
	ft_memcpy(tmp, s1, len);
	tmp[len] = 0;
	return (tmp);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
