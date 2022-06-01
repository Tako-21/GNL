/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeguedm <mmeguedm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 13:53:46 by mmeguedm          #+#    #+#             */
/*   Updated: 2022/06/01 23:22:59 by mmeguedm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(const char *string, int searchedChar )
{
	int				i;
	unsigned char	sch;

	i = 0;
	sch = searchedChar;
	while (string[i])
	{
		if (string[i] == sch)
			// return ((char *)&string[i]);
			return (1);
		i++;
	}
	if (string[i] == sch)
		return (1);
	return (0);
}

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

char	*ft_strjoin(char *line, char *buffer)
{
	char	*p;
	int		i;
	int		j;

	j = 0;
	i = 0;
	p = malloc(sizeof(char) * (ft_strlen((char *)line)
		+ ft_strlen((char *)buffer)) + 1);
	if (!p)
		return (NULL);
	while (line[i] && line[i] != '\n')
	{
		p[i] = line[i];
		i++;
	}
	while (buffer[j])
	{
		p[i] = buffer[j];
		i++;
		j++;
	}
	p[i] = '\0';
	if (*line)
		free(line);
	return (p);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}
