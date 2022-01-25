#include <iostream>
template <typename T>
T average(T a,T b);

int main(void)
{
	using namespace std;
	cout << average<int>(3,6) << "\n"
		<< average<double>(3.0,6.0) << endl;
	return 0;
}

template <typename T>
T average(T a,T b)
{
	return (a + b) / 2;
}
