#include "get_next_line/get_next_line.h"
#include <fcntl.h>

int main()
{
	/*TEST MANDATORY*/
	//int	fd = open("file", O_RDONLY);
	//char *str = "";
	//get_next_line(NULL);
	
	//if (fd != -1)
	//{
	//	while (str)
	//	{
	//		str = get_next_line(fd);
	//		printf("%s", str);
	//		free(str);
	//	}
	//}
	
	/*TEST USER INPUT*/
	//while ((str = get_next_line(0)))
	//{
	//	printf("%s", str);
	//}
	
	/*TEST MITIPLE FILES*/
	int fda = open("filea", O_RDONLY);
	int fdb = open("fileb", O_RDONLY);
	int fdc = open("filec", O_RDONLY);
	
	char *str;
	
	str = get_next_line(fda);
	printf("%s", str);
	
	str = get_next_line(fdb);
	printf("%s", str);
	
	str = get_next_line(fdc);
	printf("%s", str);
	
	str = get_next_line(fdc);
	printf("%s", str);
	
	str = get_next_line(fda);
	printf("%s", str);
	
	str = get_next_line(fdb);
	printf("%s", str);
	
	str = get_next_line(fda);
	printf("%s", str);
	
	str = get_next_line(fdc);
	printf("%s", str);
	
	str = get_next_line(fdb);
	printf("%s", str);
	
	return (0);
}