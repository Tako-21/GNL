/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 13:53:15 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/06/01 23:26:43 by mmeguedm         ###   ########.fr       */
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

void	ft_cleanbuf(char *buffer)
{
	int32_t	end;
	int32_t	start;

	start = 0;
	end = 0;
	while (buffer[end] != '\n' && buffer[end])
		end++;
	end++;
	while (start < BUFFER_SIZE + 1 && (buffer[end] != '\n') && (buffer[end] != '\0'))
	{
			buffer[start] = buffer[start + end];
			start++;
	}
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
	while (!(strchr(line, '\n'))) // GERER RESTE ELEMENTS BUFF
	{
		read(fd, buffer, BUFFER_SIZE);
		line = ft_strjoin(line, buffer);
		// if (count > 0)
			// printf("line : %s\n", line);
		if (ft_newline(line, fd))
		{
			ft_cleanbuf(buffer);
			printf("buffer : %s\n", buffer);
			count++;
			return (ft_strcut(line));
		}
	}
	count++;
	printf("buffer : %s\n", buffer);
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
}
