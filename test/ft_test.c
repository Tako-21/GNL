#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

void	ft_cleanbuf(char *buffer)
{
	int32_t	end;
	int32_t	start;

	start = 0;
	end = 0;
	while (buffer[end] != '\n' && buffer[end])
		end++;
	end++;
	while (start < 128 + 1 && (buffer[end] != '\n') && (buffer[end] != '\0'))
	{
			buffer[start] = buffer[start + end];
			start++;
	}
}


int	main(void)
{
	char	buffer[128] = "Admit impediments. Love is not love\nWhich alters when it alteration finds,";

	printf("buffer before : %s\n\n", buffer);
	ft_cleanbuf(buffer);
	printf("buffer after  : %s\n", buffer);
}
