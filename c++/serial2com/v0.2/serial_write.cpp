#include <iostream>
#include <string>
#include <sys/types.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
//#include <stdlib.h>

int open_port(int fd,int comport);
int set_opt(int fd,int nSpeed,int nBits,char nEvent,int nStop);

int main(int argc,char * argv[])
{
	using namespace std;
	int fd;
	int nwrite,arg_return;
	char buff[255] = "hello\n";
	if((fd = open_port(fd,1))<0)
	{
		perror("open_port error");
		return 0;
	}
	if((arg_return = set_opt(fd,115200,8,'N',1))<0)
	{
		perror("set_opt error");
		return 0;
	}
	cout << "opened serial fd = " << fd << endl;
	for(int index = 65535;index != 0;index--)
	{
	nwrite = write(fd,buff,8);
	cout <<"nwrite = " << nwrite << ',' << buff << "at " << index << " time" << endl;
	}
	close(fd);
	return 0;
}

int set_opt(int fd,int nSpeed,int nBits,char nEvent,int nStop)
{
	struct termios newtio,oldtio;
	//保存测试现有串口参数设置，在这里如果串口号等出错，会有相关出错信息
	if (tcgetattr(fd,&oldtio) != 0)
	{
		perror("SetupSerial 1");
		return -1;
	}
	bzero(&newtio,sizeof(newtio));
	//设置字符大小
	newtio.c_cflag |= CLOCAL | CREAD;
	newtio.c_cflag &= ~CSIZE;
	//设置停止位
	switch(nBits)
	{
		case 7:
			newtio.c_cflag |= CS7;
			break;
		case 8:
			newtio.c_cflag |= CS8;
			break;
	}
	//设置奇偶校验位
	switch(nEvent)
	{
		case 'O'://奇数
			newtio.c_cflag |= PARENB;
			newtio.c_cflag |= PARODD;
			newtio.c_iflag |= (INPCK | ISTRIP);
			break;
		case 'E'://偶数
			newtio.c_iflag |= (INPCK | ISTRIP);
			newtio.c_cflag |= PARENB;
			newtio.c_cflag &= ~PARODD;
			break;
		case 'N':
			newtio.c_cflag &= PARENB;
			break;
	}
	//设置数据传输率
	switch(nSpeed)
	{
		case 2400:
			cfsetispeed(&newtio,B2400);
			cfsetospeed(&newtio,B2400);
			break;
		case 4800:
			cfsetispeed(&newtio,B4800);
			cfsetospeed(&newtio,B4800);
			break;
		case 9600:
			cfsetispeed(&newtio,B9600);
			cfsetospeed(&newtio,B9600);
			break;
		case 115200:
			cfsetispeed(&newtio,B115200);
			cfsetospeed(&newtio,B115200);
			break;
		case 460800:
			cfsetispeed(&newtio,B460800);
			cfsetospeed(&newtio,B460800);
			break;
		default:
			cfsetispeed(&newtio,B2400);
			cfsetospeed(&newtio,B2400);
			break;
	}
	//设置停止位
	if (nStop == 1)
		newtio.c_cflag &= ~CSTOPB;
	else if (nStop == 2)
		newtio.c_cflag |= CSTOPB;
	//设置等待时间和最小接收字符
	newtio.c_cc[VTIME] = 0;
	newtio.c_cc[VMIN] = 0;
	//处理未接收字符
	tcflush(fd,TCIFLUSH);
	//激活新配置
	if((tcsetattr(fd,TCSANOW,&newtio)) != 0)
	{
		perror("com set error");
		return -1;
	}
	std::cout << "set done!" << std::endl;
	return 0;
}

int open_port(int fd,int comport)
{
	//char *dev[] {"/dev/cuau1","/dev/cuau2","/dev/cuau3"};
	//long vdisable;
	if (comport == 1)//串口1
	{
		fd = open("/dev/ttyu1",O_RDWR|O_NOCTTY|O_NDELAY);
		if (-1 == fd)
		{
			perror("Can't Open Serial Port");
			return -1;
		}
	}
	else if(comport == 2)//串口2
	{
		fd = open("/dev/ttyu2",O_RDWR|O_NOCTTY|O_NDELAY);
		if (-1 == fd)
		{
			perror("Can't Open Serial Port");
			return -1;
		}
	}
	else if (comport == 3)//串口3
	{
		fd = open("/dev/ttyu3",O_RDWR|O_NOCTTY|O_NDELAY);
		if (-1 == fd)
		{
			perror("Can't Open Serial Port");
			return -1;
		}
	}
	//恢复串口为阻塞状态
	if(fcntl(fd,F_SETFL,0)<0)
		std::cout << "fcntl failed!" << std::endl;
	else
		std::cout << "fcntl = " << fcntl(fd,F_SETFL,0) << std::endl;
	//测试是否为终端设备
	if (isatty(STDIN_FILENO) == 0)
		std::cout << "standard input is not a terminal device" << std::endl;

	else
		std::cout << "isatty success!" << std::endl;
		return fd;
}

