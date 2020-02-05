#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "stdio.h"
#include <limits.h>

int			main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		ret;
	argc = 2;
	fd = open( argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%d | %s\n", ret, line);
		//printf("ret : %d\n", ret);
		free(line);
	}
	printf("%d | %s\n", ret, line);
	free(line);
	//	system ("leaks a.out");*/
	/*
	   printf("%d  |  ", get_next_line(fd, &line));
	   printf("%s\n", line);
	   free(line);
	   printf("%d  |  ", get_next_line(fd, &line));
	   printf("%s\n", line);
	   free(line);
	   printf("%d  |  ", get_next_line(fd, &line));
	   printf("%s\n", line);
	   free(line);
	   printf("%d  |  ", get_next_line(fd, &line));
	   printf("%s\n", line);
	   free(line);
	   printf("%d  |  ", get_next_line(fd, &line));
	   printf("%s\n", line);
	   free(line);
	   */
	//	system("leaks a.out");
	close(fd);
	print_leaks();
	return (0);
}
