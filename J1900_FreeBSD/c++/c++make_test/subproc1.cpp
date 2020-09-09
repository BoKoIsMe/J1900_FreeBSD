#include <iostream>
#include "subproc1.h"

void getSubProcText(char pCopyString[])
{
	char subString[]="subProc text";
	for(int index=0;index < sizeof subString;index++)
		pCopyString[index] = subString[index];
	pCopyString[sizeof subString] = 0;
	using namespace std;
	cout << "call subproc2 => ";
	getSubProcText1();
	cout << subString << " <= layer subproc1" <<endl;
	return;
}

