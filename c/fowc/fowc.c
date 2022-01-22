#include <unistd.h>
#include <fcntl.h>
//#include <stdio.h>

int len(char stringLen[]);

int main(int argc,char* argv[])
{
	if(argc != 0)
	{
		char filename[] = "//dev//stdout";
		char space[] = " ";
		char ctrf[] = "\n";
		int fd = open(filename,O_TTY_INIT | O_WRONLY);
		if(fd == -1)
			return -1;
		for(int index = 1;index < argc;index++)
		{
			write(fd,argv[index],len(argv[index]));
			write(fd,space,sizeof space);
		}
		write(fd,ctrf,sizeof ctrf);
		close(fd);
		return 0;
	}
	else
		return -1;
}

int len(char stringLen[])
{
	int index = 0;
	while(stringLen[index])
		index++;
	//printf("\n[%d,%d]",index,index +1);
	return index;
}
