#include <iostream>
using namespace std;
const double regularPetrolDesity = 0.725f;
double mass(double desity,double volume =1.0f);
int main(void)
{
	double petrolVolume;
	cout << "1000L regular petrol = " << mass(regularPetrolDesity) << "t(" << mass(regularPetrolDesity) * 1000 << "kg)\nyou have how many L petrol:";
	cin >> petrolVolume;
	cout << "\n" << petrolVolume << "L petrol = " << mass(regularPetrolDesity,petrolVolume / 1000) << "t(" << mass(regularPetrolDesity,petrolVolume)<< "kg)" << endl;
	return 0;
}
double mass(double desity,double volume)
{
	return desity * volume;
}
