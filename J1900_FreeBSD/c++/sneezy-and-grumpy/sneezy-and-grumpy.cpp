#include <iostream>

void sneezy(int time);
void grumpy(int &time);

int main(int argc,char* argv[])
{
	using namespace std;
	int time{20};
	sneezy(time);
	cout << "called the function-sneezy and push argument-copy [time]:" << time << endl\
		<< "the function-grumpy before calling,argument-addr [&time] storage data:" << time << endl;
	grumpy(time);
	cout << "called the function-grumpy and passed argument-addr [&time] storage data:" << time << endl;
	return 0;
}

void sneezy(int x)
{
	using namespace std;
	if (x)
		while(x--)
			cout << "x = " << x << endl;
	else
		cout << "x = " << x << endl;
	return;
}

void grumpy(int &x)
{
	using namespace std;
	if (x)
		while(x--)
			cout << "x = " << x << endl;
	else
		cout << "x = " << x << endl;
	return;
}

