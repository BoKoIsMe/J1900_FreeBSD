#include <iostream>

using namespace std;
template <typename T>
void Swap(T &a,T &b);

int main(int argc,char * argv[])
{
	auto i = -1;
	auto j = 29999;
	cout << "i, j = " << i << ", " << j << "\n";
	Swap(i,j);
	cout << "i, j = " << i << ", " << j << "\n";
	auto p = 3.1415926f;
	auto e = 2.7182818f;
	cout << "pi, e = " << p << ", " << e << "\n";
	Swap(p,e);
	cout << "pi, e = " << p << ", " << e << "\n";
	return 0;
}

template <typename T>
void Swap(T &a,T &b)
{
	T temp;
	temp =a;
	a = b;
	b =temp;
}
