/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 13:53:15 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/06/01 18:14:50 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcut(char *src)
{
	int		i;
	char	*p;

	i = 0;
	p = malloc(sizeof(char) * ft_strlen((char *)src) + 1);
	if (!p)
		return (NULL);
	while (src[i] && src[i] != '\n')
	{
		p[i] = src[i];
		i++;
	}
	free(src);
	p[i] = '\0';
	return (p);
}

static int	ft_newline(char *s, int fd)
{
	while (*s)
	{
		if (*s == '\n')
		{
			while (*s == '\n' && *s)
			{
				read(fd, s, 1);
				s++;
			}
			return (1);
		}
		s++;
	}
	return (0);
}

#include <string.h>

char	*get_next_line(int fd)
{
	char			s1[BUFFER_SIZE + 1];
	char	*s2;
	static	int		count;
	int32_t			buffer;

	printf("\\\\\\\\\\\\\\\\   CALL %d   \\\\\\\\\\\\\\\\\n\n", count++);
	buffer = BUFFER_SIZE;
	s1[BUFFER_SIZE] = 0;
	s2 = "";
	while (read(fd, s1, buffer) > 0)
	{
		// s1[buffer] = '\0';
		s2 = ft_strjoin(s2, s1);
		ft_newline(s1, fd);
		if (ft_newline(s2, fd))
			return (ft_strcut(s2));
	}
	return (s2);
}

int	main(void)
{
	int		fd;
	char	*s;

	fd = open("fichier.txt", O_RDONLY);

	s = get_next_line(fd);
	printf("gnl : %s\n\n", s);
	free(s);

	s = get_next_line(fd);
	printf("gnl : %s\n\n", s);
	free(s);

	s = get_next_line(fd);
	printf("gnl : %s\n\n", s);
	free(s);
}
