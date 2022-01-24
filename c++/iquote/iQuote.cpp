#include <iostream>
#include <string>

using namespace std;

void iquote(int quote);
void iquote(double quote);
void iquote(string quote);

int main(void)
{
	int q1 = 6888;
	double q2 = 7666.66;
	string q3 = "$3888.88";
	iquote(q1);
	iquote(q2);
	iquote(q3);
	return 0;
}

void iquote(int quote)
{
	cout << "\"" << quote << "\"" << endl;
}

void iquote(double quote)
{
	cout << "\"" << quote << "\"" << endl;
}

void iquote(string quote)
{
	cout << "\"" << quote << "\"" << endl;
}
