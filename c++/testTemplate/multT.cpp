#include <iostream>
template <typename T>
auto acc(T a,T b) ->decltype(a + b);
int main(int argc,char * argv[])
{
	using namespace std;
	auto i = 0.0,j = -20.0;
	cin >> i;
	auto x =acc(i,j);
	cout << x << endl;
	return 0;
}

template <typename T>
auto acc(T a,T b) ->decltype(a + b)
{
	return a + b;
}
	
