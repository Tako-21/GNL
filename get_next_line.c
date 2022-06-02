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

static int	ft_newline(char *s, int fd)
{
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*ft_cleanbuf(char *buffer)
{
	int32_t	end;
	int32_t	start;

	start = 0;
	end = 0;
	if (buffer[end] == '\n')
	{
		end++;
		return (&buffer[end]);
	}
	while (buffer[end] != '\n' && buffer[end])
		end++;
	end++;
	// if (buffer[end] == '\0')
	// 	return (&buffer[end]);
	return (&buffer[end]);
}

#include <string.h>

char	*get_next_line(int fd)
{
	static	char	buffer[BUFFER_SIZE + 1];
	char			*line;
	static	int		count;

	printf("\\\\\\\\\\\\\\\\   CALL %d   \\\\\\\\\\\\\\\\\n\n", count);

	// buffer = 0;
	line = (char[BUFFER_SIZE + 1]){0};
	if (buffer[0] != '\0')
	{
		line = ft_cleanbuf(buffer);
		ft_memmove(buffer, line, ft_strlen(line) + 1);
		line = (char[BUFFER_SIZE + 1]){0};
		line = ft_strjoin(line, buffer);
		count++;
		return (ft_strcut(line));
	}
	while (!(strchr(line, '\n'))) // GERER RESTE ELEMENTS BUFF
	{
		read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		line = ft_strjoin(line, buffer);
		if (ft_newline(line, fd))
		{
			ft_cleanbuf(buffer);
			count++;
			return (ft_strcut(line));
		}
	}
	count++;
	return (ft_strcut(line));
}

int	main(void)
{
	int		fd;
	char	*s;

	fd = open("fichier.txt", O_RDONLY);

	s = get_next_line(fd);
	printf("\nGNL : %s\n\n", s);
	free(s);

	s = get_next_line(fd);
	printf("\nGNL : %s\n\n", s);
	free(s);

	s = get_next_line(fd);
	printf("\nGNL : %s\n\n", s);
	free(s);

	s = get_next_line(fd);
	printf("\nGNL : %s\n\n", s);
	free(s);

	s = get_next_line(fd);
	printf("\nGNL : %s\n\n", s);
	free(s);

}
