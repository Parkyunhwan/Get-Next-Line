/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypark <ypark@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 19:43:30 by ypark             #+#    #+#             */
/*   Updated: 2021/01/11 01:09:50 by ypark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

int		main(void)
{
	int		result;
	char	**line;
	int		fd;

	fd = open("file", O_RDONLY);
	if (fd == -1)
		return (-1);
	result = get_next_line(fd, line);
	printf("%s\n", *line);
}
