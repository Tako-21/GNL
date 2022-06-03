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

char	*ft_backline(char	*line)
{
	char	*s;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (line);
	s = malloc(sizeof(char) * (i + 1));
	i++;
	while (line[i + j] && line[i + j] != '\n')
	{
		s[j] = line[i + j];
		j++;
	}
	if (line[i + j] == '\0')
	{
		// free(s);
		return (line);
	}
	// free(line);
	return (s);
}

char	*ft_afterline(char	*line)
{
	char	*s;
	int		i;
	int		j;

	printf("line1 : %s", s);

	j = 0;
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (line);
	s = malloc(sizeof(char) * (i + 1));
	i++;
	while (line[i + j] && line[i + j] != '\n')
	{
		s[j] = line[i + j];
		j++;
	}
	if (line[i + j] == '\0')
	{
		// free(s);
		printf("line : %s", s);
		return (line);
	}
	// free(line);
	return (s);
}

char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE + 1];
	static char		*line;
	int				readed;
	char			*tmp;

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
	line = ft_afterline(line);
	return (tmp);
	// return tout ce quil ya avant ton \n
	// et suprimer de ta static tout ce quil y avais avant pour ne laisse que le restant
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
		// free(s);
		}
	}
