#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 1;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcut(char *src)
{
	int		i;
	char	*p;

	i = 0;
	p = malloc(sizeof(char) * ft_strlen((char *)src) + 2);
	if (!p)
		return (NULL);
	if (src[i] == '\n')
	{
		p[0] = '\n';
		p[1] = '\0';
		printf("src : %s\n", src);
		return (p);
	}
	while (src[i] && src[i] != '\n')
	{
		p[i] = src[i];
		i++;
	}
	p[i] = src[i];
	i++;
	p[i] = '\0';
	return (p);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (((char *) src) < ((char *) dest))
	{
		while (n--)
			((char *)dest)[n] = ((char *)src)[n];
	}
	else
	{
		while (n--)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
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

int	main(void)
{
	char	buffer[128] = "Admit impediments. Love is not love\n\nWhich alters when it alteration finds,";
	char	*line;

	printf("*******FIRST CALL*******\n");
	printf("INITIAL BUFFER    : %s\n", buffer);
	printf("------------------------------------------\n");
	line = ft_strcut(buffer);
	printf("\nline : %s", line);
	line = ft_cleanbuf(buffer);
	// printf("LINE              : %s\n\n", line);
	// printf("------------------------------------------\n");
	memmove(buffer, line, ft_strlen(line) + 1);
	printf("BUFFER AFTER PARSE : %s\n\n", buffer);

	printf("*******SECOND CALL*******\n");
	line = 0;
	line = ft_strcut(buffer);
	printf("\nline : |%s|", line);
	line = ft_cleanbuf(buffer);
	printf("\nLINE              : %s\n\n", line);
	printf("------------------------------------------\n");
	ft_memmove(buffer, line, ft_strlen(line) + 1);
	printf("BUFFER AFTER PARSE : %s\n\n", buffer);

	printf("*******THIRD CALL*******\n");
	line = 0;
	line = ft_strcut(buffer);
	printf("\nline : |%s|", line);
	line = ft_cleanbuf(buffer);
	printf("\nLINE              : %s\n\n", line);
	printf("------------------------------------------\n");
	ft_memmove(buffer, line, ft_strlen(line) + 1);
	printf("BUFFER AFTER PARSE : %s\n\n", buffer);

	printf("*******FOURTH CALL*******\n");
	line = 0;
	if (buffer[0] != '\0')
	{
		line = ft_strcut(buffer);
		printf("\nline : |%s|", line);
		line = ft_cleanbuf(buffer);
		printf("\nLINE              : %s\n\n", line);
		printf("------------------------------------------\n");
		ft_memmove(buffer, ft_cleanbuf(buffer), ft_strlen(line) + 1);
		printf("BUFFER AFTER PARSE : %s\n\n", buffer);
		// free(line);
	}
}
