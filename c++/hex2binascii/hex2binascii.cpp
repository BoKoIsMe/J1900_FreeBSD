#include <iostream>
#define MAX_INT 4

int main(int argc,char * argv[])
{
	using namespace std;
	unsigned int hexnumber = 0;
	unsigned int crtbit = 0;
	cout << "input a hex number:";
	cin >> hex >> hexnumber;
	//char binascii[MAX_INT * 8 + 3] = "0x00000000000000000000000000000000";
	// 上面一行或者下面一行互斥，注释掉其中一个
	char binascii[MAX_INT * 8 + 3] = "0x!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!";
	for(int index=MAX_INT * 8;index!=0;index--)
	{
		crtbit = hexnumber % 2;
		//cout << crtbit << endl; // 如需输出中间值取消注释此行
		hexnumber = hexnumber / 2;
		//cout << hex << hexnumber << endl;// 如需输出中间值取消注释此行
		if(crtbit == 1)
			binascii[index+1] = '1';
		else if(crtbit == 0)
			binascii[index+1] = '0';
		else
		{
			cout << "idk,something error.";
			break;
		}
	}
	cout << "binary number is:" << binascii << endl;
	return 0;
}

