/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoutinh <dmoutinh@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:25:43 by dmoutinh          #+#    #+#             */
/*   Updated: 2021/03/25 16:23:31 by dmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	char	buffer[2];
	int		rd;

	while((rd = read(fd, buffer, 1)) > 0)
	{
		buffer[1] = '\0';
		**line++ = buffer[0];
		if (buffer[0] == '\n')
			return (1);	
	}
	if (rd < 0)
		return (-1);
	return (0);
}

int main(int argc, char **argv)
{
	int		fd;
	char	*line;
	if (argc == 3)
		return (0);
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	printf("%s\n", line);
	return 0;
}
