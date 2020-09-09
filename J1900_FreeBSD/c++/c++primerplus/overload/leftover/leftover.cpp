// leftover.cpp -- 重载 left() 函数
#include <iostream>
unsigned long left(unsigned long num,unsigned ct);
char * left(const char * str,int n = 1);

int main(int argv,char * argc[])
{
	using namespace std;
	const char * trip = "Hawaii!!";	// 测试值
	unsigned long n = 12345678;		// 测试值
	int index;
	char * temp;

	for (index = 1;index < 10;index++)
	{
		cout << left(n,index) << endl;
		temp = left(trip,index);
		cout << temp << endl;
		delete [] temp;				// 删除临时存在的指针
	}
	return 0;
}

// 这个函数返回num变量决定长度的前几位数字
unsigned long left(unsigned long num,unsigned ct)
{
	unsigned digits = 1;
	unsigned long n = num;

	if(ct == 0 || num == 0)
		return 0;					// 返回 0 如果无数字
	while(n /= 10)
		digits++;
	if(digits > ct)
	{
		ct = digits - ct;
		while (ct--)
			num /= 10;
		return num;					// 返回左侧ct位的数字
	}
	else							// 如果 ct >= 数字位数
		return num;					// 返回整个值
}

// 函数返回新字串的指针
// 由字串前几位组成
char * left(const char * str,int n)
{
	if(n < 0)
		n = 0;
	char * p = new char[n+1];
	int index;
	for(index = 0;index < n && str[index];index++) // 数值比较优先级大于逻辑和
		p[index] = str[index];		// 串复制，如果串内内容小于n 但是遇到了结束符 \0则提前结束串拷贝
	while (index < n)
		p[index++] = '\0';			// 设置串位值为 \0 结束符
	return p;
}

