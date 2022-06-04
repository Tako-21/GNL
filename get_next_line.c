/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 13:53:15 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/06/02 23:28:05 by mmeguedm         ###   ########.fr       */
	/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

static int	ft_newline(char *s)
{
	if (s)
	{
		while (*s)
		{
			if (*s == '\n')
				return (1);
			s++;
		}
	}
	return (0);
}

int	ft_sizemalloc(char	*line)
{
	int	i;
	int	sizemalloc;

	sizemalloc = 0;
	i = 0;
	if (line == NULL)
		return (0);
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		i++;
	while (line[i])
	{
		i++;
		sizemalloc++;
	}
	return (sizemalloc);
}

char	*ft_backline(char	*line)
{
	char	*s;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (line == NULL || line[0] == '\0')
		return (NULL);
	while (line[j] && line[j] != '\n')
		j++;
	s = malloc(sizeof(char) * (j + 2));
	if (!s)
		return (NULL);
	while (i <= j)
	{
		s[i] = line[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_afterline(char	*line)
{
	char	*s;
	int		i;
	int		j;
	int		sizemalloc;

	j = 0;
	i = 0;
	if (line == NULL || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	sizemalloc = ft_sizemalloc(line);
	while (line[j] != '\n' && line[j])
		j++;
	if (line[j] == '\n')
		j++;
	s = malloc(sizeof(char) * (sizemalloc + 2));
	if (!s)
		return (NULL);
	while (line[j])
	{
		s[i] = line[j];
		i++;
		j++;
	}
	s[i] = '\0';
	// if (line[i + j] == '\0')
	// {
	// 	printf("line afterline : %c", line[i + j]);
	// 	// free(s);
	// 	return (line);
	// }
	free(line);
	return (s);
}

char	*get_next_line(int fd)
{
	char			*tmp;
	char			buffer[BUFFER_SIZE + 1];
	static char		*line;
	int				readed;
	static	int		count = 1;

	printf("\n///////////// CALL %d/////////////\n", count++);
	tmp = NULL;
	readed = 1;
	while (readed && !ft_newline(line))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
			return (0);
		buffer[readed] = 0;
		line = ft_strjoin(line, buffer);
	}
	tmp = ft_backline(line);
	printf("line : %s\n", line);
	line = ft_afterline(line);
	return (tmp);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*s;
	int		count;

	count = CALL;
	if (argc != 2)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	while (count--)
	{
		s = get_next_line(fd);
		printf("GNL : %s", s);
		free(s);
	}
	// free(s);
	close(fd);
}
