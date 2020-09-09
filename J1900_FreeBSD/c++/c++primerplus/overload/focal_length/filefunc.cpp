// filefunc.cpp -- 使用输出流和参数的函数
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

void file_it(ostream & os,double fo,const double fe[],int n);
const int LIMIT = 5;
int main(int argc,char * argv[])
{
	ofstream fout;
	const char * fn = "ep-data.txt";
	fout.open(fn);
	if(!fout.is_open())
	{
		cout << "Can't open " << fn << ". Bye.\n";
		exit(EXIT_FAILURE);
	}
	double objective;
	cout << "Enter the focal length of your "
			"telespcope objective in mm: ";
	cin >> objective;
	double eps[LIMIT];
	cout << "Enter the focal lengths, in millimeter, of " << LIMIT << " eyepieces:\n";
	for(int index{};index < LIMIT;index++)
	{
		cout << "Eyepiece #" << index + 1 << ": ";
		cin >> eps[index];
	}
	file_it(fout,objective,eps,LIMIT);
	file_it(cout,objective,eps,LIMIT);
	cout << "Done\n";
	return 0;
}

void file_it(ostream & os,double fo,const double fe[],int n)
{
	ios_base::fmtflags initial;
	initial = os.setf(ios_base::fixed); // 保存初始化格式状态
	os.precision(0);
	os << "Focal length of objective: " << fo << " millimeters\n";
	os.setf(ios::showpoint);
	os.precision(1);
	os.width(13);
	os << "f.l. eyepiece";
	os.width(14);
	os << "magnification" << endl;
	for(int index{};index < n;index++)
	{
		os.width(13);
		os << fe[index];
		os.width(14);
		os << int(fo/fe[index] + 0.5) << endl;
	}
	os.setf(initial); //恢复初始化格式状态
}

