#include "get_next_line.h"

int main (int argc, char **argv)
{
	int fd;
	char *line;
	
	fd = open(argv[1], O_RDONLY);
	argc = 2;
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	printf("%s\n", line);
	free(line);
	close(fd);
	//print_leaks();
	return (0);
}
