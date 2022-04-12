#include <iostream>
#include <fstream>
#include <cstdlib>
int main(void)
{
	using namespace std;
	const char serialName[] = "/dev/cuau1";
	char receiveChar;
	ifstream inSerial;
	inSerial.open(serialName);
	if(!inSerial.is_open())
	{
		cout << "Could ont open the serial port. " << serialName << endl;
		cout << "Program terminating.\n";
		exit(EXIT_FAILURE);
	}
	receiveChar = inSerial.get();
	while(inSerial.good())
	{
		if(receiveChar == 0x5a)
			break;
		cout << receiveChar << ' ';
		receiveChar = inSerial.get();
	}
	inSerial.close();
	return 0;
}
