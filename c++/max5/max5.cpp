#include <iostream>

template <typename T>
T max5(const T ary[],int elm = 5);
template <typename T>
void showArray(const T ary[],int elm = 5);

int main(void)
{
	//template double max5<double>(double ary[],int); // explicit instantiation not work.
	//template int max5<int>(int ary[],int);

	using namespace std;
	double array1[] = { -999.8, 256, 0, 1207.12, 1207.11 };
	int array2[] = { 1024, 1025, 0, 256, -998 };
	cout << "double array1 = { ";
	showArray(array1);
	cout << " }\n";
	cout << "Great one is: " << max5(array1) << endl;
	cout << "int array2 = { ";
	showArray(array2);
	cout << " }\n";
	cout << "Great one is: " << max5(array2) << endl;

}

template <typename T>
T max5(const T ary[],int elm)
{
	T greatElm = 0;
	for(int index = 0;index < elm;index++)
	{
		greatElm = (greatElm > ary[index])?greatElm:ary[index];
	}
	return greatElm;
}

template <typename T>
void showArray(const T ary[],int elm)
{
	for(int index = 0;index < elm;index++)
	{
		std::cout << ary[index];
		if (index != (elm - 1))
			std::cout << ", ";
	}
}
