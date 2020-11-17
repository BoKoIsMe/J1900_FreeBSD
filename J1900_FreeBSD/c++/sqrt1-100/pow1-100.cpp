#include <iostream>
#include <math.h>
#define power 2
int main(int argc,char* argv[])
{
	using namespace std;
	int sum{0};
	for(int index{1};index<=100;index++)
	{
		sum += pow(index,power);
    		cout << "result = " << sum << endl;
	}
	return 0;
}

