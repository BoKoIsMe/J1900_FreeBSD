#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#define MAX_BUF 255

int get_command_from_serial(int sd,char *buf,int buflen);

int main(void)
{
	// open the port
	int sd;
	char buffer[MAX_BUF];
	struct termios serial_options;
	sd = open("/dev/ttyu1", O_RDWR | O_NOCTTY | O_NDELAY);
	fcntl(sd,F_SETFL,0);

	// get the current options
	tcgetattr(sd,&serial_options);

	// set raw input,1 second timeout
	serial_options.c_cflag |= (CLOCAL | CREAD);
	serial_options.c_lflag &= ~(ICANON | ECHO | ECHOE |ISIG);
	serial_options.c_cflag &= ~OPOST;
	serial_options.c_cc[VMIN] = 0;
	serial_options.c_cc[VTIME] = 0;

	// set the options
	tcsetattr(sd,TCSANOW,&serial_options);

	bzero(buffer,MAX_BUF);
	int recvd_count = get_command_from_serial(sd,buffer,MAX_BUF);

	int i = 0;
	printf("count = %d\n",i);
	
	/*
	if (strncmp(buffer,"AT",2) == 0)
	{

	// get the current options
	tcgetattr(sd,&serial_options);

	// set raw input,1 second timeout
	serial_options.c_cflag |= (CLOCAL | CREAD);
	serial_options.c_lflag &= ~(ICANON | ECHO | ECHOE |ISIG);
	serial_options.c_cflag &= ~OPOST;
	serial_options.c_cc[VMIN] = 0;
	serial_options.c_cc[VTIME] = 10;

	// set the options 
	tcsetattr(sd,TCSANOW,&serial_options);


		for (int tries = 0;tries < 3;tries++)
		{
			if(write(sd,"OK\r",3) < 3)
			{
				continue;
			}
			else
			{
				printf("Communication Established");
				break;
			}
		}
	}*/
	close(sd);
	return(0);
}

int get_command_from_serial(int sd,char *buf,int buflen)
{
	int direct_point = 0;
	int count;
	while (buf[direct_point] != '\n' || buf[direct_point] != '\r')
	{
		while ((count = read(sd,&buf[direct_point],buflen - direct_point -1)) > 0)
		{
			direct_point += count;
		}
	}
	buf[direct_point] = '\0';
	return(direct_point);
}

