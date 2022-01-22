#include <iostream>
template <typename T>
T acc(T a,T b);
int main(int argc,char * argv[])
{
	using namespace std;
	int i= 0,j = -20;
	cin >> i;
	auto x =acc(i,j);
	cout << x << endl;
	return 0;
}

template <typename T>
T acc(T a,T b)
{
	return a + b;
}
	
