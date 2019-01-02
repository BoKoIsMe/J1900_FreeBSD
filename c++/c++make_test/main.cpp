#include <iostream>
#include "subproc1.h"

#define MAX_LIMT 255

int main(int argc,char* argv[])
{
	using namespace std;
	char* pString = new char[MAX_LIMT];
	getSubProcText(pString);
	cout << pString << " <= layer main call" << endl;
	delete [] pString;
	pString = nullptr;
	return 0;
}

