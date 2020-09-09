// twotemps.cpp -- 使用重载的模板
#include <iostream>
template <typename T>
void Swap(T &a,T &b);  // 原本的模板

template <typename T>
void Swap(T *a,T *b,int n); // 新的、重载的模板

void Show(int a[]);
const int Lim = 8;

int main()
{
	using namespace std;
	int i = 10,j =20;
	cout << "i, j = " << i << ", " << j << ".\n";
	cout << "使用整形模板编译创建的交换器:\n";
	Swap(i,j);  // 匹配原本的模板
	cout << "现在 i,j = " << i << ", " << j << ".\n";

	char d1[] = { "07/04/1776\0" };
	char d2[] = { "07/20/1969\0" };

	cout << "原始字串:\n";
	cout << d1 << endl;
	cout << d2 << endl;
	Swap(d1,d2,Lim + 3);
	cout << "交换字串:\n";
	cout << d1 << endl;
	cout << d2 << endl;

	int d3[Lim] = {0,7,0,4,1,7,7,6};
	int d4[Lim] = {0,7,2,0,1,9,6,9};
	cout << "原始数组:\n";
	Show(d3);
	Show(d4);
	Swap(d3,d4,Lim);
	cout << "交换数组:\n";
	Show(d3);
	Show(d4);
	return 0;
}

template <typename T>
void Swap(T &a,T &b)
{
	T temp;
	temp =a;
	a = b;
	b = temp;
}

template <typename T>
void Swap(T a[],T b[],int n)
{
	T temp;
	for(int index = 0;index < n;index++)
	{
		temp = a[index];
		a[index] = b[index];
		b[index] = temp;
	}
}

void Show(int a[])
{
	using namespace std;
	cout << a[0] << a[1] << "/";
	cout << a[2] << a[3] << "/";
	for(int index = 4;index < Lim;index++)
		cout << a[index];
	cout << endl;
}

