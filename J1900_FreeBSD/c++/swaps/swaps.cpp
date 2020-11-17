// swaps.cpp -- 用指针交换引用的变量

#include <iostream>

void swapr(int & a, int & b); // 整形变量的别名 a,b 
void swapp(int * p, int * q); // 整形变量的指针 p,q
void swapv(int a,int b);      // 整形变量的复制

int main(int argc,char* argv[])
{
	using namespace std;
	int wallet1 = 300;
	int wallet2 = 350;
	cout << "钱包1 = $" << wallet1;
	cout << " 钱包2 = $" << wallet2 << endl;

	cout << "传递引用变量的别名交换内容:\n";
	swapr(wallet1,wallet2); // 放入变量本身为别名引用
	cout << "钱包1 = $" << wallet1;
	cout << " 钱包2 = $" << wallet2 << endl;

	cout << "再次传递引用变量的指针交换内容:\n";
	swapp(&wallet1,&wallet2); // 放入变量的地址为指针引用
	cout << "钱包1 = $" << wallet1;
	cout << " 钱包2 = $" << wallet2 << endl;

	cout << "尝试传递引用变量的数值...:\n";
	swapv(wallet1,wallet2); // 放入变量的值.....
	cout << "钱包1 = $" << wallet1;
	cout << " 钱包2 = $" << wallet2 << endl;

	return 0;
}

void swapr(int &a,int &b)
{
	int temp;
	/* 使用a,b中的数值 */
	temp = a;
	a = b;
	b = temp;
}

void swapp(int * p,int * q)
{
	int temp;
	/* 使用指针 */
	temp = *p;
	*p = *q;
	*q = temp;
}

void swapv(int a,int b)
{
	int temp;
	/* 使用数值 */
	temp = a;
	a = b;
	b = temp;
}

