#include <iostream>
template <typename T>
T great(T a,T b);

int main(void)
{
	using namespace std;
	int i = 50,j = 51;
	double long p = 3.1414596f,e = 2.7182818f;
	cout << great(i,j) << "\n";
	cout << great(p,e) << endl;
	return 0;
}

template<typename T>
T great(T a, T b)
{
	return (a > b)?a:b;
}
