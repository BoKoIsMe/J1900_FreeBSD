#include <iostream>
#include <fstream>
#include <string>
#include <termios.h>
#include <cstdlib>

int main(int argc,char * argv[])
{
	using namespace std;
	string uart1out = "/dev/ttyu1";
	string uart1in = "/dev/cuau1";
	struct termios;
	ifstream uartin;
	uartin.open(uart1in.c_str(),ios_base::in);
	if (uartin.is_open())
	{
		cout << "Serial COM1 has Open succeed." << endl;
		uartin.close();
	}

	ofstream uartout(uart1in.c_str(),ios_base::out);
	if (!uartout.is_open())
	{
		cerr << "Can't open " << uart1in << " serial for output." << endl;
		exit(EXIT_FAILURE);
	}
	string sendmsg2com = "We sending msg to serial port\n";
	uartout << sendmsg2com << endl;
	cout << "msg \"" << sendmsg2com << "\" sended to COM1." << endl;
	uartout.close();

	return 0;
}

