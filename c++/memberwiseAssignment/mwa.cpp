#include <iostream>
#include <string>

struct MWA
{
	std::string str1;
	int a;
	int b;
};

void dispMWA(MWA &temp);

int main(int argc,char * argv[])
{
	using namespace std;
	MWA m1 = {"岳飞",1,3};
	MWA m2 = {"黄沾",5,6};
	MWA q1;
	q1 =m1;
	dispMWA(q1);
	q1 = m2;
	dispMWA(q1);
	return 0;
}

void dispMWA(MWA &temp)
{
	using namespace std;
	cout << "名称:" << temp.str1 << "\n";
	cout << "数值1:" << temp.a << "\n";
	cout << "数值2:" << temp.b << "\n" <<endl;
}
