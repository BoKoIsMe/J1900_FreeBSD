#include <iostream>
#include <string>

int toupper(std::string &str);

int main(void)
{
	using namespace std;
	string buf;
	cout << "Enter a string (q to quit): ";
	getline(cin,buf);
	while(-1)
	{
		if (toupper(buf))
			{
				cout << "Bye." << endl;
				break;
			}
		cout << buf << "\n";
		cout << "Nexta string (q to quit): ";
		getline(cin,buf);

	}
	return 0;
}

int toupper(std::string &str)
{
	using namespace std;
	int count,index = 0,quitflag = 0;
	if ((str[0] == 'q' || str[0] == 'Q') && str[1] == '\0')
		quitflag = -1;
	do{
		if (str[index] >= 'a' && str[index] <= 'z')
			str[index] -= 32;
	}while(str[index++]);
	return quitflag;
}
