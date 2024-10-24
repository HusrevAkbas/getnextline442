#include "get_next_line/get_next_line.h"
#include <fcntl.h>

int main()
{
	int	fd = open("file", O_RDONLY);
	char *str = "";
	//get_next_line(NULL);
	
	if (fd != -1)
	{
		while (str)
		{
			str = get_next_line(fd);
			printf("%s", str);
			free(str);
		}
	}
	
	
	//char *str;
	//while (str = get_next_line(0))
	//{
	//	printf("%s", str);
	//}
	
	//printf("%s", get_next_line(0));
	//return (0);
}