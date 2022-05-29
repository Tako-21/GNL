/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 13:53:15 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/05/29 16:51:32 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int      ft_strlen(char *str)
{
        int     i;

        i = 0;
        while (str[i])
                i++;
        return (i);
}

char    *ft_strdup(const char *src)
{
        int             i;
        char    *p;

        i = 0;
        p = malloc(sizeof(char) * ft_strlen((char *)src) + 1);
        if (!p)
                return (NULL);
        while (src[i])
        {
                p[i] = src[i];
                i++;
        }
        p[i] = '\0';
        return (p);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
        char    *p;
        int             i;
        int             j;

        j = 0;
        i = 0;
        p = malloc(sizeof(char) * (ft_strlen((char *)s1)
                                + ft_strlen((char *)s2)) + 1);
        if (!p)
                return (NULL);
        while (s1[i])
        {
                p[i] = s1[i];
                i++;
        }
        while (s2[j])
        {
                p[i] = s2[j];
                i++;
                j++;
        }
        p[i] = '\0';
        return (p);
}

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

char	*get_next_line(int fd)
{
	char	*s1;
	char	*s2;
	char	*s3;
	int32_t		buffer;
	int32_t		byte;

	buffer = BUFFER_SIZE;
	s1 = malloc(sizeof(char) * (buffer + 1));
	s2 = "";
	s3 = NULL;
	byte = 0;
	while (byte = read(fd, s1, buffer) > 0)
	{
		s3 = ft_strjoin(s1, s2);
		printf("%s\n", s1);
		if (ft_newline(s1))
		{
			printf("actual line : %s\n", s1);
			break;
		}
		s2 = ft_strdup(s1);
	}
	printf("s3 : %s\n", s3);
}


int	main(void)
{
	int		fd;
	char	*s;

	fd = open("./fichier.txt", O_RDONLY);
	s = get_next_line(fd);
}
