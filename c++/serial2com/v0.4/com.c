#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

int init_modem(int sd);

int main(void)
{
	/* open the port */
	int sd;
	struct termios serial_options;
	sd = open("/dev/cuau2", O_RDWR | O_NOCTTY | O_NDELAY);
	fcntl(sd,F_SETFL,0);

	/* get the current options */
	tcgetattr(sd,&serial_options);

	/* set raw input,1 second timeout */
	serial_options.c_cflag |= (CLOCAL | CREAD);
	serial_options.c_lflag &= ~(ICANON | ECHO | ECHOE |ISIG);
	serial_options.c_cflag &= ~OPOST;
	serial_options.c_cc[VMIN] = 0;
	serial_options.c_cc[VTIME] = 10;

	/* set the options */
	tcsetattr(sd,TCSANOW,&serial_options);
	
	//int init_modem_flag;
	if (init_modem(sd) == -1)
		printf("init modem falied.\n");
	else
		printf("init modem success.\n");
	
	close(sd);
	return(0);
}

/* Initializing the MODEM */
int						/* 0 - 0 =MODEM ok,-1 = MODEM bad */
init_modem(int sd)		/* I - Serial port file */
{
	char buffer[255];	/* Input buffer */
	char *bufptr;		/* Current char in buffer */
	int nbytes;			/* Number of bytes read */
	int tries;			/* Number of tries so far */

	for (tries = 0;tries < 3;tries++)
	{
		/* send an AT command followed by a CR */
		if (write(sd, "AT\r",3) < 3)
			continue;

		/* read charcters into our string buffer until we get a CR or NL */
		bufptr = buffer;
		while ((nbytes = read(sd,bufptr,buffer + sizeof(buffer) - bufptr - 1)) > 0)
		{
			bufptr += nbytes;
			if (bufptr[-1] == '\n' || bufptr[-1] == '\r')
				break;
		}

		/* nul terminate the string and see if we got an OK response */
		*bufptr = '\0';

		if (strncmp(buffer,"OK",2) == 0)
			return(0);
	}

	return (-1);
}
