#include "get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	/*TEST MANDATORY*/
	int	fd = open("file", O_RDWR);
	char *str = "";

	if (fd != -1)
	{
		while (str)
		{
			str = get_next_line(fd);
			printf("%s", str);
			free(str);
			sleep(1);
		}
	}
	
	/*TEST USER INPUT*/
	//char *str;
	//while ((str = get_next_line(0)))
	//{
	//	printf("%s", str);
	//}
	
	/*TEST MITIPLE FILES*/
	//int fda = open("filea", O_RDONLY);
	//int fdb = open("fileb", O_RDONLY);
	//int fdc = open("filec", O_RDONLY);
	
	//char *str;
	
	//str = get_next_line(fda);
	//printf("%s-", str);
	//free(str);
	
	//str = get_next_line(fdb);
	//printf("%s-", str);
	//free(str);
	
	//str = get_next_line(fdc);
	//printf("%s-", str);
	//free(str);
	
	//str = get_next_line(fdc);
	//printf("%s-", str);
	//free(str);
	
	//str = get_next_line(fda);
	//printf("%s-", str);
	//free(str);
	
	//str = get_next_line(fdb);
	//printf("%s-", str);
	//free(str);
	
	//str = get_next_line(fda);
	//printf("%s-", str);
	//free(str);
	
	//str = get_next_line(fdb);
	//printf("%s-", str);
	//free(str);
	
	//str = get_next_line(fdc);
	//printf("%s-", str);
	//free(str);

	return (0);
}