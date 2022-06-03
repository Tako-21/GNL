#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(void)
{

	char	s[128];
	int		i;
	int		fd;
	int		tmp;

	tmp = BUFFER_SIZE;
	fd = 0;
	i = 50;

	fd = open("f2", O_RDONLY);
	// while (i--)
	// {
	// 	printf("value : %d\n", read(fd, s, 1));
	// 	read(fd, s, 1);
	// 	printf("read  : %s\n", s);
	// }
	printf("buffer size : %d\n", tmp);
}
