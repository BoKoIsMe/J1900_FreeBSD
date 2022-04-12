#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

int main(void)
{
	using namespace std;
	struct termios options;
	const char serialName[] = "/dev/cuau1";
	const char hostName[] = "H089";
	char clientName[5] = { 0, 0, 0, 0, 0 };
	const char EOT = 0x04;
	const char ENQ = 0x05;
	const char ACK = 0x06;
	const char NAK = 0x15;
	int status,fd = open(serialName,O_RDWR);
	char receive_char,transmit_char,get_char;
	if(fd == -1)
	{
		perror("串口无法打开");
		return -1;
	}
	int DTR_flag = TIOCM_DTR;
	ioctl(fd,TIOCMBIS,&DTR_flag);

	tcgetattr(fd,&options);
	tcflush(fd,TCIOFLUSH);
	cfsetispeed(&options,B9600);
	cfsetospeed(&options,B9600);
	status = tcsetattr(fd,TCSANOW,&options);
	if(status != 0)
	{
		perror("波特率设定错误");
		return -1;
	}
	tcflush(fd,TCIOFLUSH);
	if(tcgetattr(fd,&options) != 0)
	{
		perror("串口无法设定 1");
		return -1;
	}
	options.c_cflag &= ~CRTSCTS;
	options.c_cflag &= ~CSIZE;
	options.c_cflag |= CS8;
	options.c_cflag &= ~PARENB;
	options.c_iflag &= ~INPCK;
	options.c_cflag &= ~CSTOPB;
	options.c_oflag &= ~OPOST;
	options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
	options.c_cc[VTIME] = 1;
	options.c_cc[VMIN] = 1;
	tcflush(fd,TCIFLUSH);
	if(tcsetattr(fd,TCSANOW,&options) != 0)
	{
		perror("串口无法设定 3");
		return -1;
	}
	read(fd,&receive_char,1);
	while(receive_char != ENQ)
		read(fd,&receive_char,1);
	cout << "Receive enquiry." << endl;
	transmit_char = ACK;
	write(fd,&transmit_char,1);
	write(fd,&hostName,4);
	cout << "Transmit acknowledgment." << endl;
	while(receive_char != ACK)
		read(fd,&receive_char,1);
	read(fd,&clientName,4);
	cout << "Receive acknowledgment.[" << clientName << "]\nestablish connection?(y/n)";
	get_char = cin.get();
	if((get_char == 'y') || (get_char == 'Y'))
	{
		write(fd,&transmit_char,1);
		write(fd,hostName,4);
	}
	else
	{
		transmit_char = NAK;
		write(fd,&transmit_char,1);
		close(fd);
		return -1;
	}
	close(fd);
	return 0;
}
