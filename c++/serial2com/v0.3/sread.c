#include <stdio.h>		/* Standard input/output definitions */
#include <string.h>		/* String function definitions */
#include <unistd.h>		/* UNIX standard function definitions */
#include <fcntl.h>		/* File control definitions */
#include <errno.h>		/* Error number definitions */
#include <termios.h>	/* POSIX terminal control definitions */

/*
 * 'open_port()' - Open serial port 1.
 *
 * Returns the file descriptor on success or -1 on error.
 */

int open_port(void);

int main(void)
{
	int sd,n;
	char buff[255];
	char *pbuff = &buff[0];
	if((sd = open_port()) == -1)
		return -1;
	n = read(sd,pbuff,4);
	if (n < 0)
		fputs("read() of 4 bytes failed!\n",stderr);
	close(sd);
	printf("Received %d character at Serial Port 1,The string is:%s",n,pbuff);
	return 0;
}

int open_port(void)
{
	int sd; /* serial(file) descriptor for the port */

	sd = open("/dev/ttyu1", O_RDWR | O_NOCTTY | O_NDELAY);
	if (sd == -1)
	{
		/*
		 * Could not open the port.
		*/

		perror("open_port: Unable to open /dev/ttyu2 - ");
	}
	else
		fcntl(sd,F_SETFL,0);

	return (sd);
}

