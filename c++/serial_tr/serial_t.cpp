#include <iostream>
#include <fstream>
int main()
{
	using namespace std;
	const char EOT = 0x04;
	ofstream outSerial;
	outSerial.open("/dev/cuau1");
	outSerial << "we are one.\n" << EOT << endl;
	outSerial.close();
	return 0;
}

