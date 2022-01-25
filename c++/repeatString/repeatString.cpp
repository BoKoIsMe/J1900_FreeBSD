#include <iostream>
#include <string>
const std::string str1 = "I'm OK";
const std::string str2 = "But you're kind of stupid";
void repeat(int times,std::string str);
void repeat(std::string str);
int main(void)
{
	using namespace std;
	repeat(10,str1);
	repeat(str2);
	return 0;
}

void repeat(int times,std::string str)
{
	using namespace std;
	while(times--)
		cout << str << endl;
}

void repeat(std::string str)
{
	using namespace std;
	auto defaultTimes = 5;
	while(defaultTimes--)
		cout << str << endl;
}
