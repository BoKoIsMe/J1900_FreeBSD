#include <iostream>
#include <string>
/*
	
	帮助贴吧同学写点东西
	从键盘输入5门成绩，并计算成绩平均值 总计值 并输出

*/

struct MARK
{
	int english,math,physics,chemistry,computerScience,total{};
	double avg{0.00f};
};

struct STUDENT
{
	std::string name;
	MARK mark;
};

int main(int argc,char* argv[])
{
	using namespace std;
	STUDENT student;
	cout << "输入学生名字:";
	cin >> student.name;
	cout << "输入英语成绩:";
	cin >> student.mark.english;
	cout << "输入数学成绩:";
	cin >> student.mark.math;
	cout << "输入物理成绩:";
	cin >> student.mark.physics;
	cout << "输入化学成绩:";
	cin >> student.mark.chemistry;
	cout << "输入计算机科学成绩:";
	cin >> student.mark.computerScience;
	student.mark.total = student.mark.english 
						+ student.mark.math
						+ student.mark.physics
						+ student.mark.chemistry
						+ student.mark.computerScience;
	student.mark.avg = (double)student.mark.total / 5.0f;
	cout << endl << "信息输入完成!" << endl;
	cout << "输入信息列表" << endl
			<< " 姓名:" << student.name
			<< " 英语:" << student.mark.english
			<< " 数学:" << student.mark.math
			<< " 物理:" << student.mark.physics
			<< " 化学:" << student.mark.chemistry
			<< " 计算机科学:" << student.mark.computerScience
			<< " 平均成绩:" << student.mark.avg
			<< " 总计成绩:" << student.mark.total << endl;
	return 0;
}
