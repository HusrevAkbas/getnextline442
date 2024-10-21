#include "get_next_line/get_next_line.h"
#include <fcntl.h>

int main()
{
	int	fd = open("file", O_RDONLY);
	char *str = "";
	if (fd != -1)
	{
		//while (str)
		//{
			sleep(2);
			str = get_next_line(fd);
			printf("%s", str);
		//}
	}
	close(fd);
	return (0);
}