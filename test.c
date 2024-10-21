#include "get_next_line/get_next_line.h"
#include <fcntl.h>

int main()
{
	int	fd = open("file", O_RDONLY);
	if (fd != -1)
	{
		printf("%s", get_next_line(fd));
		//sleep(3);
		//printf("%s", get_next_line(fd));
		//sleep(3);
		//printf("%s", get_next_line(fd));
		//sleep(3);
		//printf("%s", get_next_line(fd));
		//sleep(3);
		//printf("%s", get_next_line(fd));
		//sleep(3);
		//printf("%s", get_next_line(fd));
		//sleep(3);
	}
	close(fd);
	return (0);
}