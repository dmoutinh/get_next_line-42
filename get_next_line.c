/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoutinh <dmoutinh@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:25:43 by dmoutinh          #+#    #+#             */
/*   Updated: 2021/03/25 18:15:46 by dmoutinh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*j;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!len)
	{
		if (!(j = (char *)(malloc(sizeof(char)))))
			return (NULL);
	}
	else
	{
		if (!(j = (char *)(malloc(sizeof(char) * (len - 1)))))
			return (NULL);
		while (*s1)
			j[i++] = *s1++;
		while (*s2)
			j[i++] = *s2++;
	}
	j[i] = '\0';
	return (j);
}

int	get_next_line(int fd, char **line)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*s;
	int		i;
	int		rd;
	int		endl;

	endl = 0;
	if(!(s = (char *)malloc(sizeof(char))))
		return (-1);
	*s = 0;
	while((rd = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		i = 0;
		buffer[rd] = '\0';
		while(buffer[i] != '\0')
		{
			if (buffer[i] == '\n')
			{
				endl = 1;
				buffer[i] = '\0';
			}
			i++;
		}
		if (!(s = ft_strjoin(s, buffer)))
			return (-1);
		*line = s;
		if (endl)
			return (1);	
	}
	return (rd < 0 ? -1 : 0);
}

int main(int argc, char **argv)
{
	int		fd;
	char	*line;
	if (argc == 3)
		return (0);
	fd = open(argv[1], O_RDONLY);
	while(get_next_line(fd, &line))
		printf("%s\n", line);
	return 0;
}
