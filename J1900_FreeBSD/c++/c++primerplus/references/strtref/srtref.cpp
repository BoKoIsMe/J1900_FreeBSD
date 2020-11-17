// strc_ref.cpp
// -- 使用结构引用
#include <iostream>
#include <string>

struct free_throws
{
	std::string name;
	int made;
	int attempts;
	float percent;
};

void display(const free_throws & ft);
void set_pc(free_throws & ft);
free_throws & accumulate(free_throws & target, const free_throws & source);

int main(void)
{
	using namespace std;
	//部分初始化 - 仍需将成员设置为0
	free_throws one = {"Ifelsa Branch",13,14};
	free_throws two = {"Andor Knott",10,16};
	free_throws three = {"Minnie Max",7,9};
	free_throws four = {"Whily Looper",5,9};
	free_throws five = {"Long Long",6,14};
	free_throws team = {"Throwgoods",0,0};

	// 未初始化
	free_throws dup;

	set_pc(one);
	display(one);
	accumulate(team,one);
	display(team);
	// 使用返回值为参数
	display(accumulate(team,two));
	accumulate(accumulate(team,three),four);
	display(team);
	// 使用返回值赋值
	dup = accumulate(team,five);
	cout << "显示团队:" << endl;
	display(team);
	cout << "在赋值后显示转存" << endl;
	display(dup);
	set_pc(four);
	//未周全考虑过的赋值
	accumulate(dup,five) = four;
	cout << "在不当赋值后显示转存" << endl;
	display(dup);
	return 0;
}

void display(const free_throws & ft)
{
	using std::cout;
	cout << "名字: " << ft.name << '\n';
	cout << "  制造: " << ft.made << '\t';
	cout << "企图: " << ft.attempts << '\t';
	cout << "百分比: " << ft.percent << '\n';
}

void set_pc(free_throws & ft)
{
	if (ft.attempts != 0)
		ft.percent = 100.0f *float(ft.made)/float(ft.attempts);
		else
			ft.percent = 0;
}
free_throws & accumulate(free_throws & target,const free_throws & source)
{
	target.attempts += source.attempts;
	target.made += source.made;
	set_pc(target);
	return target;
}

