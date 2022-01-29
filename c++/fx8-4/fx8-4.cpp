#include <iostream>
using namespace std;
#include <cstring> //for strlen(),strcpy()
struct stringy{
	char * str; //points to a string
	int ct;		//length of string (not counting '\0')
};

// prototypes for set(), show(), and show() go here
template<typename T>
void show(const T & stry,int len = 1);
template<> void show<stringy>(const stringy & stry,int);
//void show(const stringy & stry);
int set(stringy & dst,const char *testing);

int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be.";

	set(beany, testing);	// first argument is a reference,
							// allocates space to hold copy of testing,
							// sets str member of beany to point to the
							// new block, copies testing to new block,
							// and sets ct member of beany
	show(beany);			// prints member string once
	show(beany,2);			// prints member string twice
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);			// prints testing string once
	show(testing,3);		// prints testing string thrice
	show("Done!");
	delete [] beany.str;
	return 0;
}

template<typename T>
void show(const T & stry,int len)
{
//	cout << len << endl;
	while(len > 0)
	{
		cout << stry << endl;
		len--;
	}
}

template<> void show<stringy>(const stringy & stry,int len)
{
//	cout << len << endl;
	while(len > 0)
	{
		for(int index = 0;index != stry.ct;index++)
			cout << (char)stry.str[index];
		cout << endl;
		len--;
	}
}

/*void show(const stringy & stry)
{	
	cout << "default arrgment." << endl;
	for(int index = 0;index != stry.ct;index++)
		cout << (char)stry.str[index];
	cout << endl;
}*/

int set(stringy & dst,const char *testing)
{
	dst.ct = strlen(testing);
	dst.str = new char[dst.ct + 1];
	strcpy(dst.str,testing);
	return dst.ct;
}
