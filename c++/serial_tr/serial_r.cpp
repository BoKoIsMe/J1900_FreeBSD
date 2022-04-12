#include <iostream>
#include <fstream>
#include <cstdlib>
int main()
{
	using namespace std;
	const char serialName[] = "/dev/cuau1";
	const char EOT = 0x04;
	const char ENQ = 0x05;
	const char ACK = 0x06;
	const char NAK = 0x15;
	char receive_serial,get_char;
	ofstream outSerial;
	outSerial.open(serialName);
	ifstream inSerial;
	inSerial.open(serialName);
	if(!inSerial.is_open())
	{
		cout << "Could not open the serial 1" << serialName << endl;
		cout << "Program terminating.\n";
		exit(EXIT_FAILURE);
	}
	while(inSerial.good())
	{
	receive_serial = inSerial.get();
	outSerial << receive_serial;
	cout << receive_serial;
	}
	/*while(receive_serial != ENQ)
		receive_serial = inSerial.get();
	cout << "receive enquiry" << endl;
	outSerial << ACK;
	cout << "transmit acknowledgment" << endl;
	receive_serial = inSerial.get();
	cout << receive_serial;
	while(receive_serial == ACK)
		receive_serial = inSerial.get();
	cout << "receive acknowledgment\nestablish connection?" << endl;
	get_char = cin.get();
	if((get_char == 'y') || (get_char == 'Y'))
		outSerial << ACK;
	else
	{
		outSerial << NAK;
		inSerial.close();
		outSerial.close();
		cout << "disconnect" << endl;
		exit(EXIT_FAILURE);
	}
	cout << "established" << endl;*/
	inSerial.close();
	outSerial.close();
	return 0;
}

