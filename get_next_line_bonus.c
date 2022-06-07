/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 13:53:15 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/06/06 14:15:34 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_newline(char *s)
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

	j = 0;
	i = 0;
	if (line == NULL || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	while (line[j] != '\n' && line[j])
		j++;
	if (line[j] == '\n')
		j++;
	s = malloc(sizeof(char) * (ft_sizemalloc(line) + 10));
	if (!s)
		return (NULL);
	while (line[j])
		s[i++] = line[j++];
	s[i] = '\0';
	free(line);
	return (s);
}

char	*get_next_line(int fd)
{
	char			*tmp;
	char			*buffer;
	static char		*line[1024];
	int				readed;

	tmp = NULL;
	readed = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (readed && !ft_newline(line[fd]))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
			return (free(buffer), NULL);
		buffer[readed] = 0;
		line[fd] = ft_strjoin(line[fd], buffer);
	}
	tmp = ft_backline(line[fd]);
	line[fd] = ft_afterline(line[fd]);
	return (free(buffer), tmp);
}

// int	main(int argc, char **argv)
// {
// 	int		fd;
// 	char	*s;
// 	int		count;

// 	count = CALL;
// 	if (argc != 2)
// 		return (-1);
// 	fd = open(argv[1], O_RDONLY);
// 	while (count--)
// 	{
// 		s = get_next_line(fd);
// 		printf("GNL : %s", s);
// 		free(s);
// 	}
// 	free(s);
// 	close(fd);
// }
