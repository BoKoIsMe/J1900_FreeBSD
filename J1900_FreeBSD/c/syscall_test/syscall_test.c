// 为了gdb反编译 open() close() 和 wirte() 而写的syscall )
#include </usr/src/sys/sys/syscall.h>
#include </usr/src/sys/sys/fcntl.h>
#include <unistd.h>

int main(void)
{
	const char fpath[sizeof "/dev/pts/0\0"] = "/dev/pts/0\0";
	const char wr_text[sizeof "test syscall\n\0"] = "test syscall\n\0";
	int fd = open(fpath,O_WRONLY,0);
	if (fd != -1)
		write(fd,wr_text,sizeof wr_text);
	if (fd != -1)
		close(fd);
	return 0;
}

