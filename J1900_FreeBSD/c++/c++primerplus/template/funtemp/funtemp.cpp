// funtemp.cpp -- 使用函数模板
#include <iostream>

// 声明函数模板原型
template <typename T>
void Swap(T &a,T &b);

int main(void)
{
	using namespace std;
	int i = 10;
	int j = 20;
	cout << "i, j = " << i << ", " << j << ".\n";
	Swap(i,j); // 生成 void Swap(int &,int &)
	cout << "现在 i, j = " << i << ", " << j << ".\n";

	double x = 24.5;
	double y = 81.7;
	cout << "x, y = " << x << ", " << y << ".\n";
	Swap(x,y); // 生成 void Swap(double &,double &)
	cout << "现在 x, y = " << x << ", " << y << ".\n";

	return 0;
}

// 函数模板定义
template <typename T>
void Swap(T &a,T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

