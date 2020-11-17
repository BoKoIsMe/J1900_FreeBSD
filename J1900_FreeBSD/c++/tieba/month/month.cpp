#include <iostream>

int getMonthDay0(int dwMonth,bool leap)
{
	enum month{Jan = 1,Feb = 2,Mar = 3,Apr = 4,May = 5,Jun = 6,
				Jul = 7,Aug = 8,Sept = 9,Oct = 10 ,Nov = 11 ,Dec = 12};
	switch (dwMonth)
	{
		case Jan:
		return 31;
		case Feb:
		{
			if (leap == true)
			{
				return 29;
			}
			else
			{
				return 28;
			}
		}
		case Mar:
		return 31;
		case Apr:
		return 30;
		case May:
		return 31;
		case Jun:
		return 30;
		case Jul:
		return 31;
		case Aug:
		return 31;
		case Sept:
		return 30;
		case Oct:
		return 31;
		case Nov:
		return 30;
		case Dec:
		return 31;
		default:
		return -1;
	}
}

int getMonthDay1(int dwMonth,bool leap)
{
	enum monthDay{Feb = 28,Feb_leap = 29,Apr = 30,Jun = 30,Sept = 30,Nov = 30,
				Jan = 31,Mar = 31,May = 31,Jul = 31,Aug = 31,Oct = 31,Dec = 31};
	switch (dwMonth)
	{
		case 1:
		return Jan;
		case 2:
		if (leap == true)
		{
			return Feb_leap;
		}
		else
		{
			return Feb;
		}
		case 3:
		return Mar;
		case 4:
		return Apr;
		case 5:
		return May;
		case 6:
		return Jun;
		case 7:
		return Jul;
		case 8:
		return Aug;
		case 9:
		return Sept;
		case 10:
		return Oct;
		case 11:
		return Nov;
		case 12:
		return Dec;
		default:
		return -1;
	}
}

int main(int argc,char* argv[])
{
	using namespace std;
	int month;
	cout << "输入月份:";
	cin >> month;
	cout << "使用第一种函数得到的当前月天数:" << getMonthDay0(month,false) << endl; // 回显数值为-1是非法月输入
	cout << "使用第二种函数得到的当前月天数:" << getMonthDay1(month,true) << endl; // 回显数值为-1是非法月输入
	return 0;
}
