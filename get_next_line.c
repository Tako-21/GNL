/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 13:53:15 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/05/29 20:07:51 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_newline(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*ft_strcut(const char *src)
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
	p[i] = '\0';
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*s1;
	static char	*s2;
	static	int	count;

	int32_t		buffer;
	int32_t		byte;

	printf("%d\n", count++);
	buffer = BUFFER_SIZE;
	s1 = malloc(sizeof(char) * (buffer + 1));
	s2 = "";
	byte = 0;
	printf("s2 : %s\n", s2);
	while (byte = read(fd, s1, buffer) > 0)
	{
		s2 = ft_strjoin(s2, s1);
		if (ft_newline(s2))
		{
			//s2 = ft_strcut(s2);
			printf ("s2 : %s\n", s2);
			break;
		}
	}
	return (s2);
}

int	main(void)
{
	int		fd;
	char	*s;

	fd = open("fichier.txt", O_RDONLY);
	printf("gnl : %s\n", get_next_line(fd));
	printf("gnl : %s\n", get_next_line(fd));
}
