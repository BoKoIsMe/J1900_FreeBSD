#include <iostream>
#include <string>
using namespace std;
void song(const string name = "O.My Papa",int times = 1);
int main(void)
{
	song();
	song("dolls and dancing bear.",55);
	return 0;
}
void song(const string name,int times)
{
	cout << name << " " << times << endl;
}
