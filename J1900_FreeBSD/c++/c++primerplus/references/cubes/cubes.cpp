// cubes.cpp -- regular and reference arguments
// 立方程序 -- 通常和引用参数

#include <iostream>

double cube(double a);
double refcube(double &ra);

int main(void)
{
	using namespace std;
	double x = 5.0f;

	cout << cube(x);
	cout << " = cube of " << x << endl;
	cout << refcube(x);
	cout << " = cube of " << x << endl;
	return 0;
}

double cube(double a)
{
	a *= a * a;
	return a;
}

double refcube(double &ra)
{
	ra *= ra * ra;
	return ra;
}

